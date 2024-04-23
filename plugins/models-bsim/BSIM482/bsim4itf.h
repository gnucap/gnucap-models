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

#ifdef DEV_bsim4

#ifndef DEV_BSIM4
#define DEV_BSIM4

#include "bsim4ext.h"

extern IFparm BSIM4pTable[ ];
extern IFparm BSIM4mPTable[ ];
extern char *BSIM4names[ ];
extern int BSIM4pTSize;
extern int BSIM4mPTSize;
extern int BSIM4nSize;
extern int BSIM4iSize;
extern int BSIM4mSize;

SPICEdev B4info = {
    {   "BSIM4",
        "Berkeley Short Channel IGFET Model-4",

        &BSIM4nSize,
        &BSIM4nSize,
        BSIM4names,

        &BSIM4pTSize,
        BSIM4pTable,

        &BSIM4mPTSize,
        BSIM4mPTable,
        DEV_DEFAULT
    },
    BSIM4param,
    BSIM4mParam,
    BSIM4load,
    BSIM4setup,
    BSIM4unsetup,
    BSIM4setup,
    BSIM4temp,
    BSIM4trunc,
    NULL,
    BSIM4acLoad,
    NULL,
    BSIM4destroy,
#ifdef DELETES
    BSIM4mDelete,
    BSIM4delete,
#else /* DELETES */
    NULL,
    NULL,
#endif /* DELETES */
    BSIM4getic,
    BSIM4ask,
    BSIM4mAsk,
#ifdef AN_pz
    BSIM4pzLoad,
#else /* AN_pz */
    NULL,
#endif /* AN_pz */
#ifdef NEWCONV
    BSIM4convTest,
#else /* NEWCONV */
    NULL,
#endif /* NEWCONV */
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,

#ifdef AN_noise
    BSIM4noise,
#else   /* AN_noise */
    NULL,
#endif  /* AN_noise */

    &BSIM4iSize,
    &BSIM4mSize
};

#endif
#endif
