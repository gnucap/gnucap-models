
include Make1

all:
	for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir; \
	done

clean:
	for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir clean; \
	done

install:
	for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir install; \
	done

check:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir check; \
	done

untest_exclude = \(\[\]\)\|\(extern\)\|\(switch\)\|\(enum\)\|\(union\)\|\(constexpr\)\|\(struct\)\|\(class\)\|\(namespace\)\|\(untested\)\|\(itested\)
colon_exclude = \(public\)\|\(protected\)\|\(private\)\|\(vim\)\|\(::$$\)\|\(\/\/.*:\)\|\(^.\*\)\|\(explicit\)

# place test calls at test hooks, only our own code.
untest:
	sed -i '/${untest_exclude}/!s/{$$/{ untested();/' include/*.cc
	sed -i '/tested/!s/{\(.*\)}$$/{ untested();\1}/' include/*.cc
	sed -i '/${colon_exclude}/!s/:$$/:untested();/' include/*.cc
	sed -i '/{[[:space:]]\/\*.*\*\/$$/s/{/{untested();/' include/*.cc
