
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

# only check most recent versions
check:
	${MAKE} -C BSIM3v330 check
	${MAKE} -C BSIM483 check

.PHONY: all ${SUBDIRS:%=%-all} check clean install
