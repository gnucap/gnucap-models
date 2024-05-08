
TARGET = bsim480
$(TARGET):

include makedefs

HDRS = bsim4def.h  bsim4ext.h  bsim4itf.h wrapper.h

SPICE_VERSION = SPICE_3f


TESTDIR = ../tests
TESTCASES = b4_
GNUCAP_ARGS = -a ./${TARGET}.so

include ../Make2
include ../../Make.test
