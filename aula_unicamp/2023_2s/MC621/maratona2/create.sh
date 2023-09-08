#!/bin/bash

for i in {1..13}; do
	mkdir -p "Exercise$i"
	touch "Exercise$i/src.c"
done
