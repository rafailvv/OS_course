touch  _ex1.txt
echo Rafail >> _ex1.txt
ln _ex1.txt _ex1_1.txt
ln _ex1.txt _ex1_2.txt
ls -i _ex1.txt | awk '{print $1}' >> ex1.txt
ls -i _ex1_1.txt | awk '{print $1}' >> ex1.txt
ls -i _ex1_2.txt | awk '{print $1}' >> ex1.txt
