
SUBDIRS = \
asrc bjt bsim1 bsim2 cap cccs ccvs csw dio ind isrc \
jfet ltra mes mos1 mos2 mos3 mos6 res sw tra urc vccs \
vcvs vsrc

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
	${MAKE} -C tests check
