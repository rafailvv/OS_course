mkdir week01
touch ./week01/file.txt
echo Rafail >> ./week01/file.txt
mkdir week10
link ./week01/file.txt ./week10/_ex2.txt
find . -inum $(ls -i ./week01/file.txt | awk '{print $1}') >> ex2.txt
#find . -inum $(ls -i ./week01/file.txt | awk '{print $1}') -exec rm {} \; >> ex2.txt
