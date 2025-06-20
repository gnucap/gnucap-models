extern "C" {
  #include "bsim3v1def.h"
}

#define info	 B3v1info
#define INSTANCE BSIM3v1instance
#define MODEL	 BSIM3v1model

#define SPICE_LETTER "M"
#define DEVICE_TYPE "ngspice_bsim3v1|ngspice_bsim3"
#define MIN_NET_NODES 4
#define MAX_NET_NODES 4
#define INTERNAL_NODES 3
#define MODEL_TYPE "nmos8|pmos8|nmos50|pmos50|nmos49|pmos49"

static std::string port_names[] = {"d", "g", "s", "b"};
static std::string state_names[] = {"vbd",  "vbs",   "vgs",   "vds",    "qb",  "cqb",
				    "qg",   "cqg",   "qd",    "cqd",    "qbs", "qbd",
				    "qcheq","cqcheq","qcdump","cqcdump","tau", "qdef"};

#define IS_VALID {itested();							\
    assert(d);									\
    const COMMON_PARAMLIST* c = dynamic_cast<const COMMON_PARAMLIST*>(d->common());	\
    assert(c);									\
    double l_in = c->_params["l"].e_val(OPT::defl, d->scope()->params());	\
    double w_in = c->_params["w"].e_val(OPT::defw, d->scope()->params());	\
    double l_min = _params["lmin"].e_val(0, scope()->params());			\
    double w_min = _params["wmin"].e_val(0, scope()->params());			\
    double l_max = _params["lmax"].e_val(1, scope()->params());			\
    double w_max = _params["wmax"].e_val(1, scope()->params());			\
    trace2(d->long_label().c_str(), l_in, w_in);				\
    trace4(long_label().c_str(), l_min, l_max, w_min, w_max);			\
    return l_in >= l_min && l_in <= l_max && w_in >= w_min && w_in <= w_max;	\
  }
