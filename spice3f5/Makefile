
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
GNUCAP_ARGS = -a ./dio -a ./bjt -a ./jfet -a ./bsim2 -a ./bsim1 -a ./mes \
				  -a ./mos1 -a ./mos6
include ../Make.test

.PHONY: all ${SUBDIRS:%=%-all}
