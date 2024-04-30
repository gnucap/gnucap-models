
GNUCAP = gnucap
# TODO: load with wildcard.
# BUG: depends on attach order.
GNUCAP_ARGS = -a ../dio -a ../vbic -a ../bjt -a ../jfet -a ../bsim2 -a ../bsim1 -a ../mes \
				  -a ../mesa -a ../hfet1 -a ../hfet2

# TODO: parallel testing
check:
	../../test "${GNUCAP} ${GNUCAP_ARGS}" "" check ref

.PHONY: check
