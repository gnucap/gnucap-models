
include MakeList

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
	${MAKE} -C psp104 check
	${MAKE} -C psp104_nqs check

.PHONY: all ${SUBDIRS:%=%-all} check clean install
