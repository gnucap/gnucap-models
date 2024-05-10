
include Make1

all: ${SUBDIRS:%=%-all}

${SUBDIRS:%=%-all}: %-all:
	$(MAKE) -C $*

clean:
	for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir clean; \
	done

install:
	for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir install; \
	done

TESTDIR = ../ngspice17/tests
GNUCAP = gnucap
# TODO: load with wildcard.
# BUG: depends on attach order.
GNUCAP_ARGS = ${SUBDIRS:%=-a ./%}
GNUCAP_ARGS = -a ./bjt -a ./dio -a ./bsim2 -a ./jfet -a ./mes \
				  -a ./mos1 -a ./mos2 -a ./mos6 \
              -a ./bsim1 -a ./bsim3
include ../Make.test

.PHONY: all ${SUBDIRS:%=%-all}
