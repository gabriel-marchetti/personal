#!/bin/bash

for i in {1..13}; do
	dir="exercise$i"
	mkdir -p "$dir"
	touch "$dir/source.c"
done
