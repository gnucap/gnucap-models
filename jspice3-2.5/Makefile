
SUBDIRS = \
bjt bsim1 bsim2 cap dio disto ind jfet jj \
ltra mes mos res src sw tra urc

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
