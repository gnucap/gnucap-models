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
