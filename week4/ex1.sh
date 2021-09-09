#!/bin/sh
gcc -o ex1 ex1.c
for i in {1..10}
do
	./ex1
done
