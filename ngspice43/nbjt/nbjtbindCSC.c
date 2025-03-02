/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "nbjtdefs.h"
#include "ngspice/sperror.h"
#include "ngspice/klu-binding.h"

int
NBJTbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    NBJTmodel *model = (NBJTmodel *)inModel ;
    NBJTinstance *here ;
    BindElement i, *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->SMPkluMatrix->KLUmatrixBindStructCOO ;
    nz = (size_t)ckt->CKTmatrix->SMPkluMatrix->KLUmatrixLinkedListNZ ;

    /* loop through all the NBJT models */
    for ( ; model != NULL ; model = NBJTnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = NBJTinstances(model); here != NULL ; here = NBJTnextInstance(here))
        {
            CREATE_KLU_BINDING_TABLE(NBJTcolColPtr, NBJTcolColBinding, NBJTcolNode, NBJTcolNode);
            CREATE_KLU_BINDING_TABLE(NBJTbaseBasePtr, NBJTbaseBaseBinding, NBJTbaseNode, NBJTbaseNode);
            CREATE_KLU_BINDING_TABLE(NBJTemitEmitPtr, NBJTemitEmitBinding, NBJTemitNode, NBJTemitNode);
            CREATE_KLU_BINDING_TABLE(NBJTcolBasePtr, NBJTcolBaseBinding, NBJTcolNode, NBJTbaseNode);
            CREATE_KLU_BINDING_TABLE(NBJTcolEmitPtr, NBJTcolEmitBinding, NBJTcolNode, NBJTemitNode);
            CREATE_KLU_BINDING_TABLE(NBJTbaseColPtr, NBJTbaseColBinding, NBJTbaseNode, NBJTcolNode);
            CREATE_KLU_BINDING_TABLE(NBJTbaseEmitPtr, NBJTbaseEmitBinding, NBJTbaseNode, NBJTemitNode);
            CREATE_KLU_BINDING_TABLE(NBJTemitColPtr, NBJTemitColBinding, NBJTemitNode, NBJTcolNode);
            CREATE_KLU_BINDING_TABLE(NBJTemitBasePtr, NBJTemitBaseBinding, NBJTemitNode, NBJTbaseNode);
        }
    }

    return (OK) ;
}

int
NBJTbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    NBJTmodel *model = (NBJTmodel *)inModel ;
    NBJTinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the NBJT models */
    for ( ; model != NULL ; model = NBJTnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = NBJTinstances(model); here != NULL ; here = NBJTnextInstance(here))
        {
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(NBJTcolColPtr, NBJTcolColBinding, NBJTcolNode, NBJTcolNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(NBJTbaseBasePtr, NBJTbaseBaseBinding, NBJTbaseNode, NBJTbaseNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(NBJTemitEmitPtr, NBJTemitEmitBinding, NBJTemitNode, NBJTemitNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(NBJTcolBasePtr, NBJTcolBaseBinding, NBJTcolNode, NBJTbaseNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(NBJTcolEmitPtr, NBJTcolEmitBinding, NBJTcolNode, NBJTemitNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(NBJTbaseColPtr, NBJTbaseColBinding, NBJTbaseNode, NBJTcolNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(NBJTbaseEmitPtr, NBJTbaseEmitBinding, NBJTbaseNode, NBJTemitNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(NBJTemitColPtr, NBJTemitColBinding, NBJTemitNode, NBJTcolNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(NBJTemitBasePtr, NBJTemitBaseBinding, NBJTemitNode, NBJTbaseNode);
        }
    }

    return (OK) ;
}

int
NBJTbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    NBJTmodel *model = (NBJTmodel *)inModel ;
    NBJTinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the NBJT models */
    for ( ; model != NULL ; model = NBJTnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = NBJTinstances(model); here != NULL ; here = NBJTnextInstance(here))
        {
            CONVERT_KLU_BINDING_TABLE_TO_REAL(NBJTcolColPtr, NBJTcolColBinding, NBJTcolNode, NBJTcolNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(NBJTbaseBasePtr, NBJTbaseBaseBinding, NBJTbaseNode, NBJTbaseNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(NBJTemitEmitPtr, NBJTemitEmitBinding, NBJTemitNode, NBJTemitNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(NBJTcolBasePtr, NBJTcolBaseBinding, NBJTcolNode, NBJTbaseNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(NBJTcolEmitPtr, NBJTcolEmitBinding, NBJTcolNode, NBJTemitNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(NBJTbaseColPtr, NBJTbaseColBinding, NBJTbaseNode, NBJTcolNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(NBJTbaseEmitPtr, NBJTbaseEmitBinding, NBJTbaseNode, NBJTemitNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(NBJTemitColPtr, NBJTemitColBinding, NBJTemitNode, NBJTcolNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(NBJTemitBasePtr, NBJTemitBaseBinding, NBJTemitNode, NBJTbaseNode);
        }
    }

    return (OK) ;
}
