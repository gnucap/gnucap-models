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
#include "gendefs.h"
#include "suffix.h"

int
BSIM4delete(inModel,name,inInst)
GENmodel *inModel;
IFuid name;
GENinstance **inInst;
{
BSIM4instance **fast = (BSIM4instance**)inInst;
BSIM4model *model = (BSIM4model*)inModel;
BSIM4instance **prev = NULL;
BSIM4instance *here;

    for (; model ; model = model->BSIM4nextModel)
    {    prev = &(model->BSIM4instances);
         for (here = *prev; here ; here = *prev)
     {    if (here->BSIM4name == name || (fast && here==*fast))
          {   *prev= here->BSIM4nextInstance;
                  FREE(here);
                  return(OK);
              }
              prev = &(here->BSIM4nextInstance);
         }
    }
    return(E_NODEV);
}
