extern "C" {
  #include "diodefs.h"
}

#define info	 DIOinfo
#define INSTANCE DIOinstance
#define MODEL	 DIOmodel

#define SPICE_LETTER "D"
#define DEVICE_TYPE "ngspice_dio"
#define MIN_NET_NODES 2
#define MAX_NET_NODES 2
#define INTERNAL_NODES 1
#define NOISE_SRCS 4 // DIONSRCS
#define MODEL_TYPE "d"
#define VALUE_NAME "area"

static std::string port_names[] = {"a", "c"};
static std::string state_names[] = {};
