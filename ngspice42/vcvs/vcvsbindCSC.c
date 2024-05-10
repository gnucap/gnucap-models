/**********
Author: 2013 Francesco Lannutti
**********/

#include "ngspice/ngspice.h"
#include "ngspice/cktdefs.h"
#include "vcvsdefs.h"
#include "ngspice/sperror.h"
#include "ngspice/klu-binding.h"

int
VCVSbindCSC (GENmodel *inModel, CKTcircuit *ckt)
{
    VCVSmodel *model = (VCVSmodel *)inModel ;
    VCVSinstance *here ;
    BindElement i, *matched, *BindStruct ;
    size_t nz ;

    BindStruct = ckt->CKTmatrix->SMPkluMatrix->KLUmatrixBindStructCOO ;
    nz = (size_t)ckt->CKTmatrix->SMPkluMatrix->KLUmatrixLinkedListNZ ;

    /* loop through all the VCVS models */
    for ( ; model != NULL ; model = VCVSnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = VCVSinstances(model); here != NULL ; here = VCVSnextInstance(here))
        {
            CREATE_KLU_BINDING_TABLE(VCVSposIbrPtr, VCVSposIbrBinding, VCVSposNode, VCVSbranch);
            CREATE_KLU_BINDING_TABLE(VCVSnegIbrPtr, VCVSnegIbrBinding, VCVSnegNode, VCVSbranch);
            CREATE_KLU_BINDING_TABLE(VCVSibrNegPtr, VCVSibrNegBinding, VCVSbranch, VCVSnegNode);
            CREATE_KLU_BINDING_TABLE(VCVSibrPosPtr, VCVSibrPosBinding, VCVSbranch, VCVSposNode);
            CREATE_KLU_BINDING_TABLE(VCVSibrContPosPtr, VCVSibrContPosBinding, VCVSbranch, VCVScontPosNode);
            CREATE_KLU_BINDING_TABLE(VCVSibrContNegPtr, VCVSibrContNegBinding, VCVSbranch, VCVScontNegNode);
        }
    }

    return (OK) ;
}

int
VCVSbindCSCComplex (GENmodel *inModel, CKTcircuit *ckt)
{
    VCVSmodel *model = (VCVSmodel *)inModel ;
    VCVSinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the VCVS models */
    for ( ; model != NULL ; model = VCVSnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = VCVSinstances(model); here != NULL ; here = VCVSnextInstance(here))
        {
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VCVSposIbrPtr, VCVSposIbrBinding, VCVSposNode, VCVSbranch);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VCVSnegIbrPtr, VCVSnegIbrBinding, VCVSnegNode, VCVSbranch);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VCVSibrNegPtr, VCVSibrNegBinding, VCVSbranch, VCVSnegNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VCVSibrPosPtr, VCVSibrPosBinding, VCVSbranch, VCVSposNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VCVSibrContPosPtr, VCVSibrContPosBinding, VCVSbranch, VCVScontPosNode);
            CONVERT_KLU_BINDING_TABLE_TO_COMPLEX(VCVSibrContNegPtr, VCVSibrContNegBinding, VCVSbranch, VCVScontNegNode);
        }
    }

    return (OK) ;
}

int
VCVSbindCSCComplexToReal (GENmodel *inModel, CKTcircuit *ckt)
{
    VCVSmodel *model = (VCVSmodel *)inModel ;
    VCVSinstance *here ;

    NG_IGNORE (ckt) ;

    /* loop through all the VCVS models */
    for ( ; model != NULL ; model = VCVSnextModel(model))
    {
        /* loop through all the instances of the model */
        for (here = VCVSinstances(model); here != NULL ; here = VCVSnextInstance(here))
        {
            CONVERT_KLU_BINDING_TABLE_TO_REAL(VCVSposIbrPtr, VCVSposIbrBinding, VCVSposNode, VCVSbranch);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(VCVSnegIbrPtr, VCVSnegIbrBinding, VCVSnegNode, VCVSbranch);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(VCVSibrNegPtr, VCVSibrNegBinding, VCVSbranch, VCVSnegNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(VCVSibrPosPtr, VCVSibrPosBinding, VCVSbranch, VCVSposNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(VCVSibrContPosPtr, VCVSibrContPosBinding, VCVSbranch, VCVScontPosNode);
            CONVERT_KLU_BINDING_TABLE_TO_REAL(VCVSibrContNegPtr, VCVSibrContNegBinding, VCVSbranch, VCVScontNegNode);
        }
    }

    return (OK) ;
}
