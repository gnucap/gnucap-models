include MakeList

all: ${SUBDIRS:%=%-all}

${SUBDIRS:%=%-all}: configure_stub

${SUBDIRS:%=%-all}: %-all:
	$(MAKE) -C $*

clean: configure_stub
	for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir clean; \
	done

install: configure_stub
	for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir install; \
	done

GNUCAP = gnucap
# TODO: load with wildcard.
# BUG: depends on attach order.
GNUCAP_ARGS = -a ./dio -a ./vbic -a ./bjt -a ./jfet -a ./bsim2 -a ./bsim1 -a ./mes \
              -a ./mesa -a ./hfet1 -a ./hfet2 -a ./mos1 -a ./mos6 \
              -a ./bsim3
include ../Make.test

configure_stub:
	for i in ${SUBDIRS}; do echo "include MakeList" > $$i/Makefile; echo include ../MakeConf >> $$i/Makefile; done

.PHONY: all configure_stub ${SUBDIRS:%=%-all}
