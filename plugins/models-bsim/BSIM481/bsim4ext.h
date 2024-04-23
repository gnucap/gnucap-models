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

#ifdef __STDC__
extern int BSIM4acLoad(GENmodel *,CKTcircuit*);
extern int BSIM4ask(CKTcircuit *,GENinstance*,int,IFvalue*,IFvalue*);
extern int BSIM4convTest(GENmodel *,CKTcircuit*);
extern int BSIM4delete(GENmodel*,IFuid,GENinstance**);
extern void BSIM4destroy(GENmodel**);
extern int BSIM4getic(GENmodel*,CKTcircuit*);
extern int BSIM4load(GENmodel*,CKTcircuit*);
extern int BSIM4mAsk(CKTcircuit*,GENmodel *,int, IFvalue*);
extern int BSIM4mDelete(GENmodel**,IFuid,GENmodel*);
extern int BSIM4mParam(int,IFvalue*,GENmodel*);
extern void BSIM4mosCap(CKTcircuit*, double, double, double, double,
        double, double, double, double, double, double, double,
        double, double, double, double, double, double, double*,
        double*, double*, double*, double*, double*, double*, double*,
        double*, double*, double*, double*, double*, double*, double*,
        double*);
extern int BSIM4param(int,IFvalue*,GENinstance*,IFvalue*);
extern int BSIM4pzLoad(GENmodel*,CKTcircuit*,SPcomplex*);
extern int BSIM4setup(SMPmatrix*,GENmodel*,CKTcircuit*,int*);
extern int BSIM4temp(GENmodel*,CKTcircuit*);
extern int BSIM4trunc(GENmodel*,CKTcircuit*,double*);
extern int BSIM4noise(int,int,GENmodel*,CKTcircuit*,Ndata*,double*);
extern int BSIM4unsetup(GENmodel*,CKTcircuit*);

#else /* stdc */
extern int BSIM4acLoad();
extern int BSIM4delete();
extern void BSIM4destroy();
extern int BSIM4getic();
extern int BSIM4load();
extern int BSIM4mDelete();
extern int BSIM4ask();
extern int BSIM4mAsk();
extern int BSIM4convTest();
extern int BSIM4temp();
extern int BSIM4mParam();
extern void BSIM4mosCap();
extern int BSIM4param();
extern int BSIM4pzLoad();
extern int BSIM4setup();
extern int BSIM4trunc();
extern int BSIM4noise();
extern int BSIM4unsetup();

#endif /* stdc */
