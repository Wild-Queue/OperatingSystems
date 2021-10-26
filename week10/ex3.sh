#!/bin/bash
touch _ex3.txt
echo "Shalagin Egor" > _ex3.txt
chmod -x _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod u=rwx _ex3.txt
chmod o=rwx _ex3.txt
chmod g=- _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod a=u _ex3.txt
ls -l _ex3.txt >> ex3.txt
