/* ******************************************************************************
   *  BSIM4 4.8.1 released by Chetan Kumar Dabhi 2/15/2017                      *
   *  BSIM4 Model Equations                                                     *
   ******************************************************************************

   ******************************************************************************
   *  Copyright 2017 Regents of the University of California.                   *
   *  All rights reserved.                                                      *
   *                                                                            *
   *  Project Director: Prof. Chenming Hu.                                      *
   *  Authors: Gary W. Ng, Weidong Liu, Xuemei Xi, Mohan Dunga, Wenwei Yang     *
   *           Ali Niknejad, Shivendra Singh Parihar, Chetan Kumar Dabhi        *
   *           Yogesh Singh Chauhan, Sayeef Salahuddin, Chenming Hu             *
   ******************************************************************************

   ******************************************************************************
   *                          CMC In-Code Statement                             *
   *                                                                            *
   *  The Developer agrees that the following statement will appear in the      *
   *  model code that has been adopted as a CMC Standard.                       *
   *                                                                            *
   *  Software is distributed as is, completely without warranty or service     *
   *  support. The University of California and its employees are not liable    *
   *  for the condition or performance of the software.                         *
   *                                                                            *
   *  The University of California owns the copyright and grants users a        *
   *  perpetual, irrevocable, worldwide, non-exclusive, royalty-free license    *
   *  with respect to the software as set forth below.                          *
   *                                                                            *
   *  The University of California hereby disclaims all implied warranties.     *
   *                                                                            *
   *  The University of California grants the users the right to modify,        *
   *  copy, and redistribute the software and documentation, both within        *
   *  the user's organization and externally, subject to the following          *
   *  restrictions:                                                             *
   *                                                                            *
   *  1. The users agree not to charge for the University of California code    *
   *     itself but may charge for additions, extensions, or support.           *
   *                                                                            *
   *  2. In any product based on the software, the users agree to               *
   *     acknowledge the University of California that developed the            *
   *     software. This acknowledgment shall appear in the product              *
   *     documentation.                                                         *
   *                                                                            *
   *  3. Redistributions to others of source code and documentation must        *
   *     retain the copyright notice, disclaimer, and list of conditions.       *
   *                                                                            *
   *  4. Redistributions to others in binary form must reproduce the            *
   *     copyright notice, disclaimer, and list of conditions in the            *
   *     documentation and/or other materials provided with the                 *
   *     distribution.                                                          *
   *                                                                            *
   *  Agreed to on ______Feb. 15, 2017______________                            *
   *                                                                            *
   *  By: ____University of California, Berkeley___                             *
   *      ____Chenming Hu__________________________                             *
   *      ____Professor in Graduate School ________                             *
   *                                                                            *
   ****************************************************************************** */

#include "spice.h"
#include <stdio.h>
#include "ifsim.h"
#include "inpdefs.h"
#include "inpmacs.h"
#include "fteext.h"
#include "suffix.h"

void
INP2M(ckt,tab,current)
    GENERIC *ckt;
    INPtables *tab;
    card *current;

{

    /* Mname <node> <node> <node> <node> <model> [L=<val>]
     *       [W=<val>] [AD=<val>] [AS=<val>] [PD=<val>]
     *       [PS=<val>] [NRD=<val>] [NRS=<val>] [OFF]
     *       [IC=<val>,<val>,<val>]
     */

int type;   /* the type the model says it is */
char *line; /* the part of the current line left to parse */
char *name; /* the resistor's name */
char *nname1;   /* the first node's name */
char *nname2;   /* the second node's name */
char *nname3;   /* the third node's name */
char *nname4;   /* the fourth node's name */
GENERIC *node1; /* the first node's node pointer */
GENERIC *node2; /* the second node's node pointer */
GENERIC *node3; /* the third node's node pointer */
GENERIC *node4; /* the fourth node's node pointer */
int error;      /* error code temporary */
GENERIC *fast;  /* pointer to the actual instance */
int waslead;    /* flag to indicate that funny unlabeled number was found */
double leadval; /* actual value of unlabeled number */
char *model;    /* the name of the model */
INPmodel *thismodel;    /* pointer to model description for user's model */
GENERIC *mdfast;    /* pointer to the actual model */
IFuid uid;      /* uid for default model */

    line = current->line;
    INPgetTok(&line,&name,1);
    INPinsert(&name,tab);
    INPgetTok(&line,&nname1,1);
    INPtermInsert(ckt,&nname1,tab,&node1);
    INPgetTok(&line,&nname2,1);
    INPtermInsert(ckt,&nname2,tab,&node2);
    INPgetTok(&line,&nname3,1);
    INPtermInsert(ckt,&nname3,tab,&node3);
    INPgetTok(&line,&nname4,1);
    INPtermInsert(ckt,&nname4,tab,&node4);
    INPgetTok(&line,&model,1);
    INPinsert(&model,tab);
    thismodel = (INPmodel *)NULL;
    current->error = INPgetMod(ckt,model,&thismodel,tab);
    if(thismodel != NULL) {
        if (thismodel->INPmodType != INPtypelook("Mos1")
                && thismodel->INPmodType != INPtypelook("Mos2")
                && thismodel->INPmodType != INPtypelook("Mos3")
                && thismodel->INPmodType != INPtypelook("Mos5")
                && thismodel->INPmodType != INPtypelook("Mos6")
                && thismodel->INPmodType != INPtypelook("Mos8")
                && thismodel->INPmodType != INPtypelook("BSIM1")
                && thismodel->INPmodType != INPtypelook("BSIM2")
                && thismodel->INPmodType != INPtypelook("BSIM3")
                && thismodel->INPmodType != INPtypelook("BSIM4")
        )
    {
            LITERR("incorrect model type")
            return;
        }
        type = thismodel->INPmodType;
        mdfast = (thismodel->INPmodfast);
    } else {
    type = INPtypelook("Mos1");
    if(type < 0 ) {
        LITERR("Device type MOS1 not supported by this binary\n")
        return;
    }
        if(!tab->defMmod) {
            /* create default M model */
            IFnewUid(ckt,&uid,(IFuid)NULL,"M",UID_MODEL,(GENERIC**)NULL);
            IFC(newModel,(ckt,type,&(tab->defMmod),uid))
        }
        mdfast = tab->defMmod;
    }
    IFC(newInstance,(ckt,mdfast,&fast,name))
    IFC(bindNode,(ckt,fast,1,node1))
    IFC(bindNode,(ckt,fast,2,node2))
    IFC(bindNode,(ckt,fast,3,node3))
    IFC(bindNode,(ckt,fast,4,node4))
    PARSECALL((&line,ckt,type,fast,&leadval,&waslead,tab))
    if(waslead) {
        LITERR(" error:  no unlabeled parameter permitted on mosfet\n")
    }
}
