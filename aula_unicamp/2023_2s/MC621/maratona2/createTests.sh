#!/bin/bash

for i in {1..13}; do
	for j in {1..4}; do
		cd "./Exercise$i"
		touch "example$j.txt"
	done
done
