/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "vsrcdefs.h"
#include "ngspice/sperror.h"
#include "ngspice/klu-binding.h"

int
VSRCbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    VSRCmodel *model = (VSRCmodel *)inModel ;
    VSRCinstance *here ;
    BindElement i, *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->SMPkluMatrix->KLUmatrixBindStructCOO ;
    nz = (size_t)ckt->CKTmatrix->SMPkluMatrix->KLUmatrixLinkedListNZ ;

    /* loop through all the VSRC models */
    for ( ; model != NULL ; model = VSRCnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = VSRCinstances(model); here != NULL ; here = VSRCnextInstance(here))
        {

#ifdef RFSPICE
            if (here->VSRCisPort)
            {
                CREATE_KLU_BINDING_TABLE(VSRCposPosPtr, VSRCposPosBinding, VSRCposNode, VSRCposNode);
                CREATE_KLU_BINDING_TABLE(VSRCnegNegPtr, VSRCresResBinding, VSRCresNode, VSRCresNode);
                CREATE_KLU_BINDING_TABLE(VSRCposNegPtr, VSRCposResBinding, VSRCposNode, VSRCresNode);
                CREATE_KLU_BINDING_TABLE(VSRCnegPosPtr, VSRCresPosBinding, VSRCresNode, VSRCposNode);

                CREATE_KLU_BINDING_TABLE(VSRCposIbrPtr, VSRCposIbrBinding, VSRCresNode, VSRCbranch);
                CREATE_KLU_BINDING_TABLE(VSRCnegIbrPtr, VSRCnegIbrBinding, VSRCnegNode, VSRCbranch);
                CREATE_KLU_BINDING_TABLE(VSRCibrNegPtr, VSRCibrNegBinding, VSRCbranch, VSRCnegNode);
                CREATE_KLU_BINDING_TABLE(VSRCibrPosPtr, VSRCibrPosBinding, VSRCbranch, VSRCresNode);
            }
            else
            {
                CREATE_KLU_BINDING_TABLE(VSRCposIbrPtr, VSRCposIbrBinding, VSRCposNode, VSRCbranch);
                CREATE_KLU_BINDING_TABLE(VSRCnegIbrPtr, VSRCnegIbrBinding, VSRCnegNode, VSRCbranch);
                CREATE_KLU_BINDING_TABLE(VSRCibrNegPtr, VSRCibrNegBinding, VSRCbranch, VSRCnegNode);
                CREATE_KLU_BINDING_TABLE(VSRCibrPosPtr, VSRCibrPosBinding, VSRCbranch, VSRCposNode);
            }
#else
            CREATE_KLU_BINDING_TABLE(VSRCposIbrPtr, VSRCposIbrBinding, VSRCposNode, VSRCbranch);
            CREATE_KLU_BINDING_TABLE(VSRCnegIbrPtr, VSRCnegIbrBinding, VSRCnegNode, VSRCbranch);
            CREATE_KLU_BINDING_TABLE(VSRCibrNegPtr, VSRCibrNegBinding, VSRCbranch, VSRCnegNode);
            CREATE_KLU_BINDING_TABLE(VSRCibrPosPtr, VSRCibrPosBinding, VSRCbranch, VSRCposNode);
#endif

            /* Pole-Zero Analysis */
            if (here->VSRCibrIbrPtr)
            {
                i.COO = here->VSRCibrIbrPtr ;
                i.CSC = NULL ;
                i.CSC_Complex = NULL ;
                matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ;
                here->VSRCibrIbrBinding = matched ;
                if (matched != NULL)
                {
                    here->VSRCibrIbrPtr = matched->CSC ;
                }
            }
        }
    }

    return (OK) ;
}

int
VSRCbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    VSRCmodel *model = (VSRCmodel *)inModel ;
    VSRCinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the VSRC models */
    for ( ; model != NULL ; model = VSRCnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = VSRCinstances(model); here != NULL ; here = VSRCnextInstance(here))
        {

#ifdef RFSPICE
            if (here->VSRCisPort)
            {
                CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VSRCposPosPtr, VSRCposPosBinding, VSRCposNode, VSRCposNode);
                CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VSRCnegNegPtr, VSRCresResBinding, VSRCresNode, VSRCresNode);
                CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VSRCposNegPtr, VSRCposResBinding, VSRCposNode, VSRCresNode);
                CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VSRCnegPosPtr, VSRCresPosBinding, VSRCresNode, VSRCposNode);

                CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VSRCposIbrPtr, VSRCposIbrBinding, VSRCresNode, VSRCbranch);
                CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VSRCnegIbrPtr, VSRCnegIbrBinding, VSRCnegNode, VSRCbranch);
                CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VSRCibrNegPtr, VSRCibrNegBinding, VSRCbranch, VSRCnegNode);
                CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VSRCibrPosPtr, VSRCibrPosBinding, VSRCbranch, VSRCresNode);
            }
            else
            {
                CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VSRCposIbrPtr, VSRCposIbrBinding, VSRCposNode, VSRCbranch);
                CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VSRCnegIbrPtr, VSRCnegIbrBinding, VSRCnegNode, VSRCbranch);
                CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VSRCibrNegPtr, VSRCibrNegBinding, VSRCbranch, VSRCnegNode);
                CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VSRCibrPosPtr, VSRCibrPosBinding, VSRCbranch, VSRCposNode);
            }
#else
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VSRCposIbrPtr, VSRCposIbrBinding, VSRCposNode, VSRCbranch);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VSRCnegIbrPtr, VSRCnegIbrBinding, VSRCnegNode, VSRCbranch);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VSRCibrNegPtr, VSRCibrNegBinding, VSRCbranch, VSRCnegNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VSRCibrPosPtr, VSRCibrPosBinding, VSRCbranch, VSRCposNode);
#endif

            /* Pole-Zero Analysis */
            if ((here-> VSRCbranch != 0) && (here-> VSRCbranch != 0))
            {
                if (here->VSRCibrIbrBinding)
                {
                    here->VSRCibrIbrPtr = here->VSRCibrIbrBinding->CSC_Complex ;
                }
            }
        }
    }

    return (OK) ;
}

int
VSRCbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    VSRCmodel *model = (VSRCmodel *)inModel ;
    VSRCinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the VSRC models */
    for ( ; model != NULL ; model = VSRCnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = VSRCinstances(model); here != NULL ; here = VSRCnextInstance(here))
        {

#ifdef RFSPICE
            if (here->VSRCisPort)
            {
                CONVERT_KLU_BINDING_TABLE_TO_REAL(VSRCposPosPtr, VSRCposPosBinding, VSRCposNode, VSRCposNode);
                CONVERT_KLU_BINDING_TABLE_TO_REAL(VSRCnegNegPtr, VSRCresResBinding, VSRCresNode, VSRCresNode);
                CONVERT_KLU_BINDING_TABLE_TO_REAL(VSRCposNegPtr, VSRCposResBinding, VSRCposNode, VSRCresNode);
                CONVERT_KLU_BINDING_TABLE_TO_REAL(VSRCnegPosPtr, VSRCresPosBinding, VSRCresNode, VSRCposNode);

                CONVERT_KLU_BINDING_TABLE_TO_REAL(VSRCposIbrPtr, VSRCposIbrBinding, VSRCresNode, VSRCbranch);
                CONVERT_KLU_BINDING_TABLE_TO_REAL(VSRCnegIbrPtr, VSRCnegIbrBinding, VSRCnegNode, VSRCbranch);
                CONVERT_KLU_BINDING_TABLE_TO_REAL(VSRCibrNegPtr, VSRCibrNegBinding, VSRCbranch, VSRCnegNode);
                CONVERT_KLU_BINDING_TABLE_TO_REAL(VSRCibrPosPtr, VSRCibrPosBinding, VSRCbranch, VSRCresNode);
            }
            else
            {
                CONVERT_KLU_BINDING_TABLE_TO_REAL(VSRCposIbrPtr, VSRCposIbrBinding, VSRCposNode, VSRCbranch);
                CONVERT_KLU_BINDING_TABLE_TO_REAL(VSRCnegIbrPtr, VSRCnegIbrBinding, VSRCnegNode, VSRCbranch);
                CONVERT_KLU_BINDING_TABLE_TO_REAL(VSRCibrNegPtr, VSRCibrNegBinding, VSRCbranch, VSRCnegNode);
                CONVERT_KLU_BINDING_TABLE_TO_REAL(VSRCibrPosPtr, VSRCibrPosBinding, VSRCbranch, VSRCposNode);
            }
#else
            CONVERT_KLU_BINDING_TABLE_TO_REAL(VSRCposIbrPtr, VSRCposIbrBinding, VSRCposNode, VSRCbranch);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(VSRCnegIbrPtr, VSRCnegIbrBinding, VSRCnegNode, VSRCbranch);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(VSRCibrNegPtr, VSRCibrNegBinding, VSRCbranch, VSRCnegNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(VSRCibrPosPtr, VSRCibrPosBinding, VSRCbranch, VSRCposNode);
#endif

            /* Pole-Zero Analysis */
            if ((here-> VSRCbranch != 0) && (here-> VSRCbranch != 0))
            {
                if (here->VSRCibrIbrBinding)
                {
                    here->VSRCibrIbrPtr = here->VSRCibrIbrBinding->CSC ;
                }
            }
        }
    }

    return (OK) ;
}
