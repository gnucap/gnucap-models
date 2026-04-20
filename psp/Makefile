
include MakeList

all: ${SUBDIRS:%=%-all}
install: ${SUBDIRS:%=%-install}

${SUBDIRS:%=%-all}: %-all:
	$(MAKE) -C $* all
${SUBDIRS:%=%-install}: %-install:
	$(MAKE) -C $* install

clean:
	for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir clean; \
	done

# only check most recent versions
check:
	${MAKE} -C psp104 check
	${MAKE} -C psp104_nqs check

.PHONY: all ${SUBDIRS:%=%-all} check clean install
