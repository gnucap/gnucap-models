/* ******************************************************************************
   *  BSIM4 4.8.3 released on 05/19/2025                                        *
   *  BSIM4 Model Equations                                                     *
   ******************************************************************************

   ******************************************************************************
   *  Copyright (c) 2025 University of California                               *
   *                                                                            *
   *  Project Directors: Prof. Sayeef Salahuddin and Prof. Chenming Hu          *
   *  Developers list: https://www.bsim.berkeley.edu/models/bsim4/auth_bsim4/   * 
   ******************************************************************************/

/*
Licensed under Educational Community License, Version 2.0 (the "License"); you may
not use this file except in compliance with the License. You may obtain a copy of the license at
http://opensource.org/licenses/ECL-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT 
WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations
under the License.

BSIM4 model is supported by the members of Silicon Integration Initiative's Compact Model Coalition. A link to the most recent version of this
standard can be found at: http://www.si2.org/cmc 
*/

#include "spice.h"
#include <stdio.h>
#include "util.h"
#include "bsim4def.h"
#include "sperror.h"
#include "suffix.h"

int
BSIM4mDelete(inModel,modname,kill)
GENmodel **inModel;
IFuid modname;
GENmodel *kill;
{
BSIM4model **model = (BSIM4model**)inModel;
BSIM4model *modfast = (BSIM4model*)kill;
BSIM4instance *here;
BSIM4instance *prev = NULL;
BSIM4model **oldmod;

    oldmod = model;
    for (; *model ; model = &((*model)->BSIM4nextModel))
    {    if ((*model)->BSIM4modName == modname ||
             (modfast && *model == modfast))
         goto delgot;
         oldmod = model;
    }
    return(E_NOMOD);

delgot:
    *oldmod = (*model)->BSIM4nextModel; /* cut deleted device out of list */
    for (here = (*model)->BSIM4instances; here; here = here->BSIM4nextInstance)
    {    if(prev) FREE(prev);
         prev = here;
    }
    if(prev) FREE(prev);
    FREE(*model);
    return(OK);
}
