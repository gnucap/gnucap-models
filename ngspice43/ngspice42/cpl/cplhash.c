/**********
Copyright 2021 The ngspice team  All rights
reserved.
Author: 2021 Holger Vogt
3-clause BSD license
**********/

/* This is a test file including a local garbage collector and removal.
It might be especially useful, because cpl transmission lines have
several memory leaks during runtime in difficult to control process
sequence..
At initialization in CPLsetup() mem_init() is called setting up a hash table
to store memory addresses.
Each time TMALLOC is called, the resulting address is stored.
Each time tfree() is called, the address is removed.
For realloc(), the old address is deleted, the new one is stored,
if there is a change in the address.
Upon exiting the program, mem_delete() is called, deleting all memory
at addresses still in the hash table, then the hash table itself is removed.
CPLunsetup() calls mem_delete(). */

#include "ngspice/ngspice.h"
#include "ngspice/iferrmsg.h"
#include "ngspice/hash.h"
#include "ngspice/fteext.h"
#include "cpldefs.h"

// #define DB_FULL /* uncomment for debugging output, all addresses to files */
#ifdef DB_FULL
#define DB
#else
#define DB /* uncomment for printing some debugging output */
#endif

void mem_init(void);
void mem_delete(void);

int memsaved(void *ptr);
void memdeleted(const void *ptr);

void my_free_func(void* data);
void my_key_free(void* key);

int gc_is_on = 0;

/* add some debugging printout */
#ifdef DB
static int mem_in = 0, mem_out = 0, mem_freed = 0;
#endif
#ifdef DB_FULL
static FILE *alloclog, *freelog, *finallog;
#endif

NGHASHPTR memory_table;

/* initialize hash table to store allocated mem addresses */
void mem_init(void) {
    gc_is_on = 0;
    memory_table = nghash_init_pointer(1024);
    gc_is_on = 1;
#ifdef DB_FULL
    alloclog = fopen("alloc_log.txt", "wt");
    freelog = fopen("free_log.txt", "wt");
    finallog = fopen("final_log.txt", "wt");
#endif
}

/* add to counter and hash table if memory is allocated */
int memsaved(void *ptr) {
    if (gc_is_on) {
        gc_is_on = 0;

        if (nghash_insert(memory_table, ptr, NULL) == NULL) {
#ifdef DB
            mem_in++;
#ifdef DB_FULL
            fprintf(alloclog, "0x%p\n", ptr);
#endif
#endif
        } else
            fprintf(stderr, "Warning: CPL GC Could not insert item into hashtable at 0x%p\n", ptr);
        gc_is_on = 1;
    }
    return OK;
}

/* add to counter and remove from hash table if memory is deleted */
void memdeleted(const void *ptr) {
    if (gc_is_on) {
        gc_is_on = 0;
        if (nghash_delete_special(memory_table, (void*)ptr) == NULL) {
#ifdef DB
            mem_out++;
#ifdef DB_FULL
            fprintf(freelog, "0x%p\n", ptr);
#endif
        }
        else if (ft_ngdebug)
            fprintf(stderr, "Warning: CPL GC Could not delete item from hashtable at 0x%p\n", ptr);
#else
        }
#endif
        gc_is_on = 1;
    }
}

/* helper functions */
void my_free_func(void *data)
{
    if (data)
        free(data);
}

void my_key_free(void * key)
{
    if (key) {
        free(key);
        key = NULL;
#ifdef DB
        mem_freed++;
#endif
    }
}

/* free hash table, all entries and then the table itself */
void mem_delete(void) {
#ifdef DB
    char buf[128];
    if (!memory_table)
        return;
    printf("CPL GC memory allocated %d times, freed %d times\n", mem_in, mem_out);
    printf("CPL GC size of hash table to be freed: %d entries.\n", nghash_get_size(memory_table));
#ifdef DB_FULL
    void *data, *key;
    data = nghash_enumeratek(memory_table, &key, TRUE);
    for (void *hkey = key; hkey;) {
        fprintf(finallog, "0x%p\n", hkey);
        data = nghash_enumeratek(memory_table, &hkey, FALSE);
    }
    fclose(alloclog);
    fclose(freelog);
    fclose(finallog);
#endif
#endif
    gc_is_on = 0;
    nghash_free(memory_table, NULL, my_key_free);
    memory_table = NULL;
#ifdef DB
    /* printf via sh_printf will need some info from variables that have
    been deleted already, therefore we use fputs */
    sprintf(buf, "CPL GC number of addresses freed: %d entries.\n", mem_freed);
    fputs(buf, stdout);
#endif
    pool_vi = NULL;
    mem_freed = mem_in = mem_out = 0;
}
