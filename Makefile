
SUBDIRS = \
	bsim \
	jspice3-2.5 \
	ngspice17 \
	spice3f5

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
