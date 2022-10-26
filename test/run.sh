#!/bin/bash

cat ./forward.h |
while read line
do
     echo $line;
     /home/indemind/Code/codetest/test/cmake-build-debug/test $line test1;
     
done


