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
#include "iferrmsg.h"
#include "util.h"
#include "inpdefs.h"
#include "strext.h"
#include "suffix.h"

/*ARGSUSED*/
char *
INPdomodel(ckt,image,tab)
    GENERIC *ckt;
    card *image;
    INPtables *tab;
{

    char *modname;
    int type;
    int lev;
    char *typename;
    char *err = (char *)NULL;
    char *line;

    line = image->line;
    INPgetTok(&line,&modname,1);  /* throw away '.model' */
    INPgetTok(&line,&modname,1);
    INPinsert(&modname,tab);
    INPgetTok(&line,&typename,1);
    if( (strcmp(typename,"npn") == 0)||(strcmp(typename,"pnp")==0) ) {
        type = INPtypelook("BJT");
        if(type < 0) {
            err = INPmkTemp("Device type BJT not available in this binary\n");
        }
        INPmakeMod(modname,type,image);
    } else if(strcmp(typename,"d") == 0) {
        type = INPtypelook("Diode");
        if(type < 0) {
            err = INPmkTemp("Device type Diode not available in this binary\n");
        }
        INPmakeMod(modname,type,image);
    } else if( (strcmp(typename,"njf") == 0) || (strcmp(typename,"pjf") == 0)){
        type = INPtypelook("JFET");
        if(type < 0) {
            err = INPmkTemp("Device type JFET not available in this binary\n");
        }
        INPmakeMod(modname,type,image);
    } else if( (strcmp(typename,"nmf") == 0) || (strcmp(typename,"pmf")==0) ) {
        type = INPtypelook("MES");
        if(type < 0) {
            err = INPmkTemp("Device type MES not available in this binary\n");
        }
        INPmakeMod(modname,type,image);
    } else if(strcmp(typename,"urc") == 0) {
        type = INPtypelook("URC");
        if(type < 0) {
            err = INPmkTemp("Device type URC not available in this binary\n");
        }
        INPmakeMod(modname,type,image);
    } else if( (strcmp(typename,"nmos")==0) || (strcmp(typename,"pmos")==0) ) {
        err = INPfindLev(line,&lev);
        switch(lev) {
            case 0:
            case 1:
                type = INPtypelook("Mos1");
                if(type < 0) {
                    err = INPmkTemp(
                            "Device type MOS1 not available in this binary\n");
                }
                break;
            case 2:
                type = INPtypelook("Mos2");
                if(type < 0) {
                    err = INPmkTemp(
                            "Device type MOS2 not available in this binary\n");
                }
                break;
            case 3:
                type = INPtypelook("Mos3");
                if(type < 0) {
                    err = INPmkTemp(
                            "Device type MOS3 not available in this binary\n");
                }
                break;
            case 4:
                type = INPtypelook("BSIM1");
                if(type < 0) {
                    err = INPmkTemp(
                            "Device type BSIM1 not available in this binary\n");
                }
                break;
            case 5:
                type = INPtypelook("BSIM2");
                if(type < 0) {
                    err = INPmkTemp(
                            "Device type BSIM2 not available in this binary\n");
                }
                break;
            case 6:
                type = INPtypelook("Mos6");
                if(type < 0) {
                    err = INPmkTemp(
                            "Device type MOS6 not available in this binary\n");
                }
                break;
            case 7:
                type = INPtypelook("MOS7");
                if(type < 0) {
                    err = INPmkTemp(
                            "Device type MOS7 not available in this binary\n");
                }
                break;
            case 8:
                type = INPtypelook("BSIM3");
                if(type < 0) {
                    err = INPmkTemp(
                            "Device type BSIM3 not available in this binary\n");
                }
                break;
            case 9:
                type = INPtypelook("BSIMsoi");
                if(type < 0) {
                    err = INPmkTemp(
                            "Device type BSIMsoi not available in this binary\n");
                }
                break;
            case 14:
                type = INPtypelook("BSIM4");
                if(type < 0) {
                    err = INPmkTemp(
                            "Device type BSIM4 not available in this binary\n");
                }
                break;
            case 15:
                type = INPtypelook("BSIM5");
                if(type < 0) {
                    err = INPmkTemp(
                            "Placeholder: Device type BSIM5 not available in this binary\n");
                }
                break;
            case 16:
                type = INPtypelook("BSIM6");
                if(type < 0) {
                    err = INPmkTemp(
                            "Placeholder: Device type BSIM6 not available in this binary\n");
                }
                break;
            default: /* Use level 17 or higher levels for the other models */
        err = INPmkTemp(
          "Only MOS device levels 1-14 are supported in this binary\n");
                break;
        }
        INPmakeMod(modname,type,image);
    } else if(strcmp(typename,"r") == 0) {
        type = INPtypelook("Resistor");
        if(type < 0) {
            err = INPmkTemp(
                    "Device type Resistor not available in this binary\n");
        }
        INPmakeMod(modname,type,image);
    } else if(strcmp(typename,"c") == 0) {
        type = INPtypelook("Capacitor");
        if(type < 0) {
            err = INPmkTemp(
                    "Device type Capacitor not available in this binary\n");
        }
        INPmakeMod(modname,type,image);
    } else if(strcmp(typename,"sw") == 0) {
        type = INPtypelook("Switch");
        if(type < 0) {
            err = INPmkTemp(
                    "Device type Switch not available in this binary\n");
        }
        INPmakeMod(modname,type,image);
    } else if(strcmp(typename,"csw") == 0) {
        type = INPtypelook("CSwitch");
        if(type < 0) {
            err = INPmkTemp(
                    "Device type CSwitch not available in this binary\n");
        }
        INPmakeMod(modname,type,image);
    } else if(strcmp(typename,"ltra") == 0) {
        type = INPtypelook("LTRA");
        if(type < 0) {
            err = INPmkTemp(
                    "Device type LTRA not available in this binary\n");
        }
        INPmakeMod(modname,type,image);
    } else {
        type = -1;
        err = (char *)MALLOC(35 + strlen(typename));
        (void)sprintf(err,"unknown model type %s - ignored\n",typename);
    }
    return(err);
}
