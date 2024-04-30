/* ******************************************************************************
   *  BSIM4 4.8.2 released by Chetan Kumar Dabhi 01/01/2020                     *
   *  BSIM4 Model Equations                                                     *
   ******************************************************************************

   ******************************************************************************
   *  Copyright (c) 2020 University of California                               *
   *                                                                            *
   *  Project Director: Prof. Chenming Hu.                                      *
   *  Current developers: Chetan Kumar Dabhi   (Ph.D. student, IIT Kanpur)      *
   *                      Prof. Yogesh Chauhan (IIT Kanpur)                     *
   *                      Dr. Pragya Kushwaha  (Postdoc, UC Berkeley)           *
   *                      Dr. Avirup Dasgupta  (Postdoc, UC Berkeley)           *
   *                      Ming-Yen Kao         (Ph.D. student, UC Berkeley)     *
   *  Authors: Gary W. Ng, Weidong Liu, Xuemei Xi, Mohan Dunga, Wenwei Yang     *
   *           Ali Niknejad, Chetan Kumar Dabhi, Yogesh Singh Chauhan,          *
   *           Sayeef Salahuddin, Chenming Hu                                   * 
   ******************************************************************************/

/*
Licensed under Educational Community License, Version 2.0 (the "License"); you may
not use this file except in compliance with the License. You may obtain a copy of the license at
http://opensource.org/licenses/ECL-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT 
WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations
under the License.

BSIM-CMG model is supported by the members of Silicon Integration Initiative's Compact Model Coalition. A link to the most recent version of this
standard can be found at: http://www.si2.org/cmc 
*/

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
