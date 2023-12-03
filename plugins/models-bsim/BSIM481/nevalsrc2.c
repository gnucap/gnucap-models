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

/*
 * NevalSrc2 (noise, lnNoise, ckt, type, node1, node2, param, node3, node4, param2)
 *   This routine is a modified version of NevalSrc() that computes
 *   the output noise due to two fully-correlated noise sources. It is
 *   useful for implementing correlated gate and drain noises in MOSFETs.
 *
 *   Like NevalSrc(), it evaluates the noise due to different physical
 *   phenomena.  This includes the "shot" noise associated with dc
 *   currents in semiconductors and the "thermal" noise associated with
 *   resistance.  Although semiconductors also display "flicker" (1/f)
 *   noise, the lack of a unified model requires us to handle it on a
 *   "case by case" basis.  What we CAN provide, though, is the noise
 *   gain associated with the 1/f source.
 */
/* Modified by Darsen Lu for BSIM4 tnoiMod=2 10/10/2010
*/

#include "spice.h"
#include "cktdefs.h"
#include "const.h"
#include "noisedef.h"
#include "util.h"
#include "suffix.h"

void
NevalSrc2 (noise, lnNoise, ckt, type, node1, node2, param1, node3, node4, param2, phi21)

double *noise;
double *lnNoise;
CKTcircuit *ckt;
int type;
int node1;
int node2;
double param1;
int node3;
int node4;
double param2;
double phi21;     /* Phase of signal 2 relative to signal 1 */

{
    double realVal1, imagVal1;
    double realVal2, imagVal2;
    double realOut, imagOut, param_gain;
    double T0, T1, T2, T3;

    realVal1 = *((ckt->CKTrhs) + node1) - *((ckt->CKTrhs) + node2);
    imagVal1 = *((ckt->CKTirhs) + node1) - *((ckt->CKTirhs) + node2);
    realVal2 = *((ckt->CKTrhs) + node3) - *((ckt->CKTrhs) + node4);
    imagVal2 = *((ckt->CKTirhs) + node3) - *((ckt->CKTirhs) + node4);
    T0 = sqrt(param1);
    T1 = sqrt(param2);
    T2 = T1 * cos(phi21);
    T3 = T1 * sin(phi21);
    realOut = T0 * realVal1 + T2 * realVal2 - T3 * imagVal2;
    imagOut = T0 * imagVal1 + T2 * imagVal2 + T3 * realVal2;
    param_gain = (realOut*realOut) + (imagOut*imagOut);
    switch (type) {

    case SHOTNOISE:
    *noise = 2.0 * CHARGE * FABS(param_gain);          /* param is the dc current in a semiconductor */
    *lnNoise = log( MAX(*noise,N_MINLOG) );
    break;

    case THERMNOISE:
    *noise = 4.0 * CONSTboltz * ckt->CKTtemp * param_gain;         /* param is the conductance of a resistor */
        *lnNoise = log( MAX(*noise,N_MINLOG) );
        break;

    case N_GAIN:
    *noise = 0.0;
    break;

    }
}
