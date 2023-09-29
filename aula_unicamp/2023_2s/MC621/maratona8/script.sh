#!/bin/bash

for i in {A..J}; do
	mkdir -p "Exercise$i"
	touch "Exercise$i/$i.cpp"
	touch "Exercise$i/test.txt"
	touch "Exercise$i/makefile"
	echo "all:" > "Exercise$i/makefile"
	echo "	g++ std=c++11 -o $i $i.cpp" >> "Exercise$i/makefile"
done
