mkdir tmp
touch ./tmp/file1.txt
touch ./tmp/file2.txt
ln ./tmp/file1.txt ./tmp/link1.txt
gcc ex4.c -o ex4
./ex4 > ex4.txt
cat ex4.txt
