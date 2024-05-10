/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "numd2def.h"
#include "ngspice/sperror.h"
#include "ngspice/klu-binding.h"

int
NUMD2bindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    NUMD2model *model = (NUMD2model *)inModel ;
    NUMD2instance *here ;
    BindElement i, *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->SMPkluMatrix->KLUmatrixBindStructCOO ;
    nz = (size_t)ckt->CKTmatrix->SMPkluMatrix->KLUmatrixLinkedListNZ ;

    /* loop through all the NUMD2 models */
    for ( ; model != NULL ; model = NUMD2nextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = NUMD2instances(model); here != NULL ; here = NUMD2nextInstance(here))
        {
            CREATE_KLU_BINDING_TABLE(NUMD2posPosPtr, NUMD2posPosBinding, NUMD2posNode, NUMD2posNode);
            CREATE_KLU_BINDING_TABLE(NUMD2negNegPtr, NUMD2negNegBinding, NUMD2negNode, NUMD2negNode);
            CREATE_KLU_BINDING_TABLE(NUMD2negPosPtr, NUMD2negPosBinding, NUMD2negNode, NUMD2posNode);
            CREATE_KLU_BINDING_TABLE(NUMD2posNegPtr, NUMD2posNegBinding, NUMD2posNode, NUMD2negNode);
        }
    }

    return (OK) ;
}

int
NUMD2bindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    NUMD2model *model = (NUMD2model *)inModel ;
    NUMD2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the NUMD2 models */
    for ( ; model != NULL ; model = NUMD2nextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = NUMD2instances(model); here != NULL ; here = NUMD2nextInstance(here))
        {
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(NUMD2posPosPtr, NUMD2posPosBinding, NUMD2posNode, NUMD2posNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(NUMD2negNegPtr, NUMD2negNegBinding, NUMD2negNode, NUMD2negNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(NUMD2negPosPtr, NUMD2negPosBinding, NUMD2negNode, NUMD2posNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(NUMD2posNegPtr, NUMD2posNegBinding, NUMD2posNode, NUMD2negNode);
        }
    }

    return (OK) ;
}

int
NUMD2bindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    NUMD2model *model = (NUMD2model *)inModel ;
    NUMD2instance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the NUMD2 models */
    for ( ; model != NULL ; model = NUMD2nextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = NUMD2instances(model); here != NULL ; here = NUMD2nextInstance(here))
        {
            CONVERT_KLU_BINDING_TABLE_TO_REAL(NUMD2posPosPtr, NUMD2posPosBinding, NUMD2posNode, NUMD2posNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(NUMD2negNegPtr, NUMD2negNegBinding, NUMD2negNode, NUMD2negNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(NUMD2negPosPtr, NUMD2negPosBinding, NUMD2negNode, NUMD2posNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(NUMD2posNegPtr, NUMD2posNegBinding, NUMD2posNode, NUMD2negNode);
        }
    }

    return (OK) ;
}
