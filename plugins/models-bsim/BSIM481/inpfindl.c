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

/* INPfindLev(line)
 * Find the 'level' parameter value on the model file
 * The BSIM4 model is level 14 in SPICE3.
 * Please note BSIM5 and BSIM6 will take level 15 and 16 in the future, respectively.
 */

#include "spice.h"
#include "misc.h"
#include "strext.h"
#include <stdio.h>
#include "inpdefs.h"
#include "util.h"
#include "suffix.h"

char *
INPfindLev(line,level)
    char *line;
    int *level;
{   char *where;
    char LevArray[3]; /* save individual level numerals */
    char *LevNumString; /* points to the level string */
    int i_array = 0;
    where = line;

    while(1)
    { where = index(where,'l');
      if(where == 0) /* no 'l' in the line => no 'level' => default */
      { *level = 14; /* the default model is BSIM4 */
        return((char *)NULL);
      }
      if(strncmp(where,"level",5)!=0)
      { /* this l isn't in the word 'level', try again */
        where++;    /* make sure we don't match same char again */
        continue;
      }
      /* The word level found, lets look at the rest of the line */
      where += 5;
      while((*where == ' ') || (*where == '\t') || (*where == '=') ||
           (*where == ',') || (*where == '(') || (*where == ')') ||
           (*where == '+'))
      { where++;
      }

      LevNumString = LevArray;
      while(!((*where == ' ') || (*where == '\t') || (*where == '=') ||
           (*where == ',') || (*where == '(') || (*where == ')') ||
           (*where == '+')))
      { LevArray[i_array] = *where;
        i_array++;
        where++;
      }
      LevArray[i_array] = '\0';

      if (strcmp(LevNumString, "1") == 0)
      {  *level=1;
         return((char *)NULL);
      }
      else if (strcmp(LevNumString, "2") == 0)
      {  *level=2;
         return((char *)NULL);
      }
      else if (strcmp(LevNumString, "3") == 0)
      {  *level=3;
         return((char *)NULL);
      }
      else if (strcmp(LevNumString, "4") == 0)
      {  *level=4;
         return((char *)NULL);
      }
      else if (strcmp(LevNumString, "5") == 0)
      {  *level=5;
         return((char *)NULL);
      }
      else if (strcmp(LevNumString, "6") == 0)
      {  *level=6;
         return((char *)NULL);
      }
      else if (strcmp(LevNumString, "7") == 0)
      {  *level=7;
         return((char *)NULL);
      }
      else if (strcmp(LevNumString, "8") == 0)
      {  *level=8;
         return((char *)NULL);
      }
      else if (strcmp(LevNumString, "9") == 0)
      {  *level=9;
         return((char *)NULL);
      }
      else if (strcmp(LevNumString, "10") == 0)
      {  *level=10;
         return((char *)NULL);
      }
      else if (strcmp(LevNumString, "11") == 0)
      {  *level=11;
         return((char *)NULL);
      }
      else if (strcmp(LevNumString, "12") == 0)
      {  *level=12;
         return((char *)NULL);
      }
      else if (strcmp(LevNumString, "13") == 0)
      {  *level=13;
         return((char *)NULL);
      }
      else if (strcmp(LevNumString, "14") == 0)
      {  *level=14;
         return((char *)NULL);
      }
      else
      {  *level=14;
         printf("illegal argument to 'level' - BSIM4 assumed\n");
         return(INPmkTemp("illegal argument to 'level' - BSIM4 assumed"));
      }
    }
}
