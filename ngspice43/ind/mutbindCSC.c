/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "inddefs.h"
#include "ngspice/sperror.h"
#include "ngspice/klu-binding.h"

int
MUTbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    MUTmodel *model = (MUTmodel *)inModel ;
    MUTinstance *here ;
    BindElement i, *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->SMPkluMatrix->KLUmatrixBindStructCOO ;
    nz = (size_t)ckt->CKTmatrix->SMPkluMatrix->KLUmatrixLinkedListNZ ;

    /* loop through all the MUT models */
    for ( ; model != NULL ; model = MUTnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = MUTinstances(model); here != NULL ; here = MUTnextInstance(here))
        {
            CREATE_KLU_BINDING_TABLE(MUTbr1br2Ptr, MUTbr1br2Binding, MUTind1->INDbrEq, MUTind2->INDbrEq);
            CREATE_KLU_BINDING_TABLE(MUTbr2br1Ptr, MUTbr2br1Binding, MUTind2->INDbrEq, MUTind1->INDbrEq);
        }
    }

    return (OK) ;
}

int
MUTbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    MUTmodel *model = (MUTmodel *)inModel ;
    MUTinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MUT models */
    for ( ; model != NULL ; model = MUTnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = MUTinstances(model); here != NULL ; here = MUTnextInstance(here))
        {
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(MUTbr1br2Ptr, MUTbr1br2Binding, MUTind1->INDbrEq, MUTind2->INDbrEq);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(MUTbr2br1Ptr, MUTbr2br1Binding, MUTind2->INDbrEq, MUTind1->INDbrEq);
        }
    }

    return (OK) ;
}

int
MUTbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    MUTmodel *model = (MUTmodel *)inModel ;
    MUTinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the MUT models */
    for ( ; model != NULL ; model = MUTnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = MUTinstances(model); here != NULL ; here = MUTnextInstance(here))
        {
            CONVERT_KLU_BINDING_TABLE_TO_REAL(MUTbr1br2Ptr, MUTbr1br2Binding, MUTind1->INDbrEq, MUTind2->INDbrEq);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(MUTbr2br1Ptr, MUTbr2br1Binding, MUTind2->INDbrEq, MUTind1->INDbrEq);
        }
    }

    return (OK) ;
}
