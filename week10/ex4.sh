#!/bin/bash
mkdir tmp
touch ./tmp/file1.txt
touch ./tmp/file2.txt
ln ./tmp/file1.txt link1
gcc ex4.c -o ex4
./ex4
