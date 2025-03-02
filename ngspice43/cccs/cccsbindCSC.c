/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "cccsdefs.h"
#include "ngspice/sperror.h"
#include "ngspice/klu-binding.h"

int
CCCSbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    CCCSmodel *model = (CCCSmodel *)inModel ;
    CCCSinstance *here ;
    BindElement i, *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->SMPkluMatrix->KLUmatrixBindStructCOO ;
    nz = (size_t)ckt->CKTmatrix->SMPkluMatrix->KLUmatrixLinkedListNZ ;

    /* loop through all the CCCS models */
    for ( ; model != NULL ; model = CCCSnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = CCCSinstances(model); here != NULL ; here = CCCSnextInstance(here))
        {
            CREATE_KLU_BINDING_TABLE(CCCSposContBrPtr, CCCSposContBrBinding, CCCSposNode, CCCScontBranch);
            CREATE_KLU_BINDING_TABLE(CCCSnegContBrPtr, CCCSnegContBrBinding, CCCSnegNode, CCCScontBranch);
        }
    }

    return (OK) ;
}

int
CCCSbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    CCCSmodel *model = (CCCSmodel *)inModel ;
    CCCSinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the CCCS models */
    for ( ; model != NULL ; model = CCCSnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = CCCSinstances(model); here != NULL ; here = CCCSnextInstance(here))
        {
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(CCCSposContBrPtr, CCCSposContBrBinding, CCCSposNode, CCCScontBranch);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(CCCSnegContBrPtr, CCCSnegContBrBinding, CCCSnegNode, CCCScontBranch);
        }
    }

    return (OK) ;
}

int
CCCSbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    CCCSmodel *model = (CCCSmodel *)inModel ;
    CCCSinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the CCCS models */
    for ( ; model != NULL ; model = CCCSnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = CCCSinstances(model); here != NULL ; here = CCCSnextInstance(here))
        {
            CONVERT_KLU_BINDING_TABLE_TO_REAL(CCCSposContBrPtr, CCCSposContBrBinding, CCCSposNode, CCCScontBranch);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(CCCSnegContBrPtr, CCCSnegContBrBinding, CCCSnegNode, CCCScontBranch);
        }
    }

    return (OK) ;
}
