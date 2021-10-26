mkdir week01
mkdir week10
touch ./week01/file.txt
link ./week01/file.txt ./week10/_ex2.txt
ls -i ./week01/file.txt > find ./week01/file.txt -inum > ./ex2.txt
find ./week01/file.txt -inum 1442527 -exec rm {} \;
