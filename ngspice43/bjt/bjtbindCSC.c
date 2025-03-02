/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "bjtdefs.h"
#include "ngspice/sperror.h"
#include "ngspice/klu-binding.h"

int
BJTbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    BJTmodel *model = (BJTmodel *)inModel ;
    BJTinstance *here ;
    BindElement i, *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->SMPkluMatrix->KLUmatrixBindStructCOO ;
    nz = (size_t)ckt->CKTmatrix->SMPkluMatrix->KLUmatrixLinkedListNZ ;

    /* loop through all the BJT models */
    for ( ; model != NULL ; model = BJTnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = BJTinstances(model); here != NULL ; here = BJTnextInstance(here))
        {
            CREATE_KLU_BINDING_TABLE(BJTcollCollCXPtr,         BJTcollCollCXBinding,         BJTcolNode,       BJTcollCXNode);
            CREATE_KLU_BINDING_TABLE(BJTbaseBasePrimePtr,      BJTbaseBasePrimeBinding,      BJTbaseNode,      BJTbasePrimeNode);
            CREATE_KLU_BINDING_TABLE(BJTemitEmitPrimePtr,      BJTemitEmitPrimeBinding,      BJTemitNode,      BJTemitPrimeNode);
            CREATE_KLU_BINDING_TABLE(BJTcollCXCollPtr,         BJTcollCXCollBinding,         BJTcollCXNode,    BJTcolNode);
            CREATE_KLU_BINDING_TABLE(BJTcolPrimeBasePrimePtr,  BJTcolPrimeBasePrimeBinding,  BJTcolPrimeNode,  BJTbasePrimeNode);
            CREATE_KLU_BINDING_TABLE(BJTcolPrimeEmitPrimePtr,  BJTcolPrimeEmitPrimeBinding,  BJTcolPrimeNode,  BJTemitPrimeNode);
            CREATE_KLU_BINDING_TABLE(BJTbasePrimeBasePtr,      BJTbasePrimeBaseBinding,      BJTbasePrimeNode, BJTbaseNode);
            CREATE_KLU_BINDING_TABLE(BJTbasePrimeColPrimePtr,  BJTbasePrimeColPrimeBinding,  BJTbasePrimeNode, BJTcolPrimeNode);
            CREATE_KLU_BINDING_TABLE(BJTbasePrimeEmitPrimePtr, BJTbasePrimeEmitPrimeBinding, BJTbasePrimeNode, BJTemitPrimeNode);
            CREATE_KLU_BINDING_TABLE(BJTemitPrimeEmitPtr,      BJTemitPrimeEmitBinding,      BJTemitPrimeNode, BJTemitNode);
            CREATE_KLU_BINDING_TABLE(BJTemitPrimeColPrimePtr,  BJTemitPrimeColPrimeBinding,  BJTemitPrimeNode, BJTcolPrimeNode);
            CREATE_KLU_BINDING_TABLE(BJTemitPrimeBasePrimePtr, BJTemitPrimeBasePrimeBinding, BJTemitPrimeNode, BJTbasePrimeNode);
            CREATE_KLU_BINDING_TABLE(BJTcolColPtr,             BJTcolColBinding,             BJTcolNode,       BJTcolNode);
            CREATE_KLU_BINDING_TABLE(BJTbaseBasePtr,           BJTbaseBaseBinding,           BJTbaseNode,      BJTbaseNode);
            CREATE_KLU_BINDING_TABLE(BJTemitEmitPtr,           BJTemitEmitBinding,           BJTemitNode,      BJTemitNode);
            CREATE_KLU_BINDING_TABLE(BJTcolPrimeColPrimePtr,   BJTcolPrimeColPrimeBinding,   BJTcolPrimeNode,  BJTcolPrimeNode);
            CREATE_KLU_BINDING_TABLE(BJTbasePrimeBasePrimePtr, BJTbasePrimeBasePrimeBinding, BJTbasePrimeNode, BJTbasePrimeNode);
            CREATE_KLU_BINDING_TABLE(BJTemitPrimeEmitPrimePtr, BJTemitPrimeEmitPrimeBinding, BJTemitPrimeNode, BJTemitPrimeNode);
            CREATE_KLU_BINDING_TABLE(BJTsubstSubstPtr,         BJTsubstSubstBinding,         BJTsubstNode,     BJTsubstNode);
            if (model -> BJTsubs == LATERAL) {
              here -> BJTsubstConNode = here -> BJTbasePrimeNode;
              here -> BJTsubstConSubstConPtr = here -> BJTbasePrimeBasePrimePtr;
            } else {
              here -> BJTsubstConNode = here -> BJTcolPrimeNode;
              here -> BJTsubstConSubstConPtr = here -> BJTcolPrimeColPrimePtr;
            }
            CREATE_KLU_BINDING_TABLE(BJTsubstConSubstPtr,      BJTsubstConSubstBinding,      BJTsubstConNode,  BJTsubstNode);
            CREATE_KLU_BINDING_TABLE(BJTsubstSubstConPtr,      BJTsubstSubstConBinding,      BJTsubstNode,     BJTsubstConNode);
            CREATE_KLU_BINDING_TABLE(BJTbaseColPrimePtr,       BJTbaseColPrimeBinding,       BJTbaseNode,      BJTcolPrimeNode);
            CREATE_KLU_BINDING_TABLE(BJTcolPrimeBasePtr,       BJTcolPrimeBaseBinding,       BJTcolPrimeNode,  BJTbaseNode);

            CREATE_KLU_BINDING_TABLE(BJTcollCXcollCXPtr,       BJTcollCXcollCXBinding,       BJTcollCXNode,    BJTcollCXNode);

            if(model->BJTintCollResistGiven) {
                CREATE_KLU_BINDING_TABLE(BJTcollCXBasePrimePtr, BJTcollCXBasePrimeBinding, BJTcollCXNode,    BJTbasePrimeNode);
                CREATE_KLU_BINDING_TABLE(BJTbasePrimeCollCXPtr, BJTbasePrimeCollCXBinding, BJTbasePrimeNode, BJTcollCXNode);
                CREATE_KLU_BINDING_TABLE(BJTcolPrimeCollCXPtr,  BJTcolPrimeCollCXBinding,  BJTcolPrimeNode,  BJTcollCXNode);
                CREATE_KLU_BINDING_TABLE(BJTcollCXColPrimePtr,  BJTcollCXColPrimeBinding,  BJTcollCXNode,    BJTcolPrimeNode);
            }
        }
    }

    return (OK) ;
}

int
BJTbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    BJTmodel *model = (BJTmodel *)inModel ;
    BJTinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BJT models */
    for ( ; model != NULL ; model = BJTnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = BJTinstances(model); here != NULL ; here = BJTnextInstance(here))
        {
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTcollCollCXPtr,         BJTcollCollCXBinding,         BJTcolNode,       BJTcollCXNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTbaseBasePrimePtr,      BJTbaseBasePrimeBinding,      BJTbaseNode,      BJTbasePrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTemitEmitPrimePtr,      BJTemitEmitPrimeBinding,      BJTemitNode,      BJTemitPrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTcollCXCollPtr,         BJTcollCXCollBinding,         BJTcollCXNode,    BJTcolNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTcolPrimeBasePrimePtr,  BJTcolPrimeBasePrimeBinding,  BJTcolPrimeNode,  BJTbasePrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTcolPrimeEmitPrimePtr,  BJTcolPrimeEmitPrimeBinding,  BJTcolPrimeNode,  BJTemitPrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTbasePrimeBasePtr,      BJTbasePrimeBaseBinding,      BJTbasePrimeNode, BJTbaseNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTbasePrimeColPrimePtr,  BJTbasePrimeColPrimeBinding,  BJTbasePrimeNode, BJTcolPrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTbasePrimeEmitPrimePtr, BJTbasePrimeEmitPrimeBinding, BJTbasePrimeNode, BJTemitPrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTemitPrimeEmitPtr,      BJTemitPrimeEmitBinding,      BJTemitPrimeNode, BJTemitNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTemitPrimeColPrimePtr,  BJTemitPrimeColPrimeBinding,  BJTemitPrimeNode, BJTcolPrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTemitPrimeBasePrimePtr, BJTemitPrimeBasePrimeBinding, BJTemitPrimeNode, BJTbasePrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTcolColPtr,             BJTcolColBinding,             BJTcolNode,       BJTcolNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTbaseBasePtr,           BJTbaseBaseBinding,           BJTbaseNode,      BJTbaseNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTemitEmitPtr,           BJTemitEmitBinding,           BJTemitNode,      BJTemitNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTcolPrimeColPrimePtr,   BJTcolPrimeColPrimeBinding,   BJTcolPrimeNode,  BJTcolPrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTbasePrimeBasePrimePtr, BJTbasePrimeBasePrimeBinding, BJTbasePrimeNode, BJTbasePrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTemitPrimeEmitPrimePtr, BJTemitPrimeEmitPrimeBinding, BJTemitPrimeNode, BJTemitPrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTsubstSubstPtr,         BJTsubstSubstBinding,         BJTsubstNode,     BJTsubstNode);
            if (model -> BJTsubs == LATERAL) {
              here -> BJTsubstConNode = here -> BJTbasePrimeNode;
              here -> BJTsubstConSubstConPtr = here -> BJTbasePrimeBasePrimePtr;
            } else {
              here -> BJTsubstConNode = here -> BJTcolPrimeNode;
              here -> BJTsubstConSubstConPtr = here -> BJTcolPrimeColPrimePtr;
            }
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTsubstConSubstPtr,      BJTsubstConSubstBinding,      BJTsubstConNode,  BJTsubstNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTsubstSubstConPtr,      BJTsubstSubstConBinding,      BJTsubstNode,     BJTsubstConNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTbaseColPrimePtr,       BJTbaseColPrimeBinding,       BJTbaseNode,      BJTcolPrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTcolPrimeBasePtr,       BJTcolPrimeBaseBinding,       BJTcolPrimeNode,  BJTbaseNode);

            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTcollCXcollCXPtr,       BJTcollCXcollCXBinding,       BJTcollCXNode,    BJTcollCXNode);

            if(model->BJTintCollResistGiven) {
                CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTcollCXBasePrimePtr, BJTcollCXBasePrimeBinding, BJTcollCXNode,    BJTbasePrimeNode);
                CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTbasePrimeCollCXPtr, BJTbasePrimeCollCXBinding, BJTbasePrimeNode, BJTcollCXNode);
                CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTcolPrimeCollCXPtr,  BJTcolPrimeCollCXBinding,  BJTcolPrimeNode,  BJTcollCXNode);
                CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(BJTcollCXColPrimePtr,  BJTcollCXColPrimeBinding,  BJTcollCXNode,    BJTcolPrimeNode);
            }
        }
    }

    return (OK) ;
}

int
BJTbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    BJTmodel *model = (BJTmodel *)inModel ;
    BJTinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the BJT models */
    for ( ; model != NULL ; model = BJTnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = BJTinstances(model); here != NULL ; here = BJTnextInstance(here))
        {
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTcollCollCXPtr,         BJTcollCollCXBinding,         BJTcolNode,       BJTcollCXNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTbaseBasePrimePtr,      BJTbaseBasePrimeBinding,      BJTbaseNode,      BJTbasePrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTemitEmitPrimePtr,      BJTemitEmitPrimeBinding,      BJTemitNode,      BJTemitPrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTcollCXCollPtr,         BJTcollCXCollBinding,         BJTcollCXNode,    BJTcolNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTcolPrimeBasePrimePtr,  BJTcolPrimeBasePrimeBinding,  BJTcolPrimeNode,  BJTbasePrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTcolPrimeEmitPrimePtr,  BJTcolPrimeEmitPrimeBinding,  BJTcolPrimeNode,  BJTemitPrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTbasePrimeBasePtr,      BJTbasePrimeBaseBinding,      BJTbasePrimeNode, BJTbaseNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTbasePrimeColPrimePtr,  BJTbasePrimeColPrimeBinding,  BJTbasePrimeNode, BJTcolPrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTbasePrimeEmitPrimePtr, BJTbasePrimeEmitPrimeBinding, BJTbasePrimeNode, BJTemitPrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTemitPrimeEmitPtr,      BJTemitPrimeEmitBinding,      BJTemitPrimeNode, BJTemitNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTemitPrimeColPrimePtr,  BJTemitPrimeColPrimeBinding,  BJTemitPrimeNode, BJTcolPrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTemitPrimeBasePrimePtr, BJTemitPrimeBasePrimeBinding, BJTemitPrimeNode, BJTbasePrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTcolColPtr,             BJTcolColBinding,             BJTcolNode,       BJTcolNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTbaseBasePtr,           BJTbaseBaseBinding,           BJTbaseNode,      BJTbaseNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTemitEmitPtr,           BJTemitEmitBinding,           BJTemitNode,      BJTemitNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTcolPrimeColPrimePtr,   BJTcolPrimeColPrimeBinding,   BJTcolPrimeNode,  BJTcolPrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTbasePrimeBasePrimePtr, BJTbasePrimeBasePrimeBinding, BJTbasePrimeNode, BJTbasePrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTemitPrimeEmitPrimePtr, BJTemitPrimeEmitPrimeBinding, BJTemitPrimeNode, BJTemitPrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTsubstSubstPtr,         BJTsubstSubstBinding,         BJTsubstNode,     BJTsubstNode);
            if (model -> BJTsubs == LATERAL) {
              here -> BJTsubstConNode = here -> BJTbasePrimeNode;
              here -> BJTsubstConSubstConPtr = here -> BJTbasePrimeBasePrimePtr;
            } else {
              here -> BJTsubstConNode = here -> BJTcolPrimeNode;
              here -> BJTsubstConSubstConPtr = here -> BJTcolPrimeColPrimePtr;
            }
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTsubstConSubstPtr,      BJTsubstConSubstBinding,      BJTsubstConNode,  BJTsubstNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTsubstSubstConPtr,      BJTsubstSubstConBinding,      BJTsubstNode,     BJTsubstConNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTbaseColPrimePtr,       BJTbaseColPrimeBinding,       BJTbaseNode,      BJTcolPrimeNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTcolPrimeBasePtr,       BJTcolPrimeBaseBinding,       BJTcolPrimeNode,  BJTbaseNode);

            CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTcollCXcollCXPtr,       BJTcollCXcollCXBinding,       BJTcollCXNode,    BJTcollCXNode);

            if(model->BJTintCollResistGiven) {
                CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTcollCXBasePrimePtr, BJTcollCXBasePrimeBinding, BJTcollCXNode,    BJTbasePrimeNode);
                CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTbasePrimeCollCXPtr, BJTbasePrimeCollCXBinding, BJTbasePrimeNode, BJTcollCXNode);
                CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTcolPrimeCollCXPtr,  BJTcolPrimeCollCXBinding,  BJTcolPrimeNode,  BJTcollCXNode);
                CONVERT_KLU_BINDING_TABLE_TO_REAL(BJTcollCXColPrimePtr,  BJTcollCXColPrimeBinding,  BJTcollCXNode,    BJTcolPrimeNode);
            }
        }
    }

    return (OK) ;
}
