#!/bin/sh

FILES="comprt gstage oneshot opamp qatest ro_17 test1 test10 test11 test12 test13 test14 test2 test3 test4 test5 test6 test7 test8 test9"

for file in $FILES
do
    echo Running netlist $file.b4 ...
    spice3 -b $file.b4 > $file.out
    echo
done
