/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "capdefs.h"
#include "ngspice/sperror.h"
#include "ngspice/klu-binding.h"

int
CAPbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    CAPmodel *model = (CAPmodel *)inModel ;
    CAPinstance *here ;
    BindElement i, *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->SMPkluMatrix->KLUmatrixBindStructCOO ;
    nz = (size_t)ckt->CKTmatrix->SMPkluMatrix->KLUmatrixLinkedListNZ ;

    /* loop through all the CAP models */
    for ( ; model != NULL ; model = CAPnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = CAPinstances(model); here != NULL ; here = CAPnextInstance(here))
        {
            CREATE_KLU_BINDING_TABLE(CAPposPosPtr, CAPposPosBinding, CAPposNode, CAPposNode);
            CREATE_KLU_BINDING_TABLE(CAPnegNegPtr, CAPnegNegBinding, CAPnegNode, CAPnegNode);
            CREATE_KLU_BINDING_TABLE(CAPposNegPtr, CAPposNegBinding, CAPposNode, CAPnegNode);
            CREATE_KLU_BINDING_TABLE(CAPnegPosPtr, CAPnegPosBinding, CAPnegNode, CAPposNode);
        }
    }

    return (OK) ;
}

int
CAPbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    CAPmodel *model = (CAPmodel *)inModel ;
    CAPinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the CAP models */
    for ( ; model != NULL ; model = CAPnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = CAPinstances(model); here != NULL ; here = CAPnextInstance(here))
        {
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(CAPposPosPtr, CAPposPosBinding, CAPposNode, CAPposNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(CAPnegNegPtr, CAPnegNegBinding, CAPnegNode, CAPnegNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(CAPposNegPtr, CAPposNegBinding, CAPposNode, CAPnegNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(CAPnegPosPtr, CAPnegPosBinding, CAPnegNode, CAPposNode);
        }
    }

    return (OK) ;
}

int
CAPbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    CAPmodel *model = (CAPmodel *)inModel ;
    CAPinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the CAP models */
    for ( ; model != NULL ; model = CAPnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = CAPinstances(model); here != NULL ; here = CAPnextInstance(here))
        {
            CONVERT_KLU_BINDING_TABLE_TO_REAL(CAPposPosPtr, CAPposPosBinding, CAPposNode, CAPposNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(CAPnegNegPtr, CAPnegNegBinding, CAPnegNode, CAPnegNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(CAPposNegPtr, CAPposNegBinding, CAPposNode, CAPnegNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(CAPnegPosPtr, CAPnegPosBinding, CAPnegNode, CAPposNode);
        }
    }

    return (OK) ;
}
