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

TESTDIR = tests
GNUCAP = gnucap
# TODO: load with wildcard.
# BUG: depends on attach order.
GNUCAP_ARGS = -a ./dio -a ./vbic -a ./bjt -a ./jfet -a ./bsim2 -a ./bsim1 -a ./mes \
              -a ./mesa -a ./hfet1 -a ./hfet2 -a ./mos1 -a ./mos6 \
              -a ./bsim3
include ../Make.test

.PHONY: all ${SUBDIRS:%=%-all}
