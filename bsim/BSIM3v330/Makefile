
TARGET = bsim330
$(TARGET):

include makedefs

HDRS = bsim3def.h bsim3ext.h bsim3itf.h wrapper.h

SPICE_VERSION = SPICE_3f

TESTDIR = ../tests
TESTCASES = b3_
GNUCAP_ARGS = -a ./${TARGET}.so

include ../Make2
include ../../Make.test
