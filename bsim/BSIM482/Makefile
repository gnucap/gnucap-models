
TARGET = bsim482
$(TARGET):

include makedefs

HDRS = bsim4def.h  bsim4ext.h  bsim4itf.h wrapper.h

SPICE_VERSION = SPICE_3f

include ../Make2

TESTDIR = ../tests
TESTCASES = b4_
GNUCAP_ARGS = -a ./${TARGET}.so
include ../../Make.test
