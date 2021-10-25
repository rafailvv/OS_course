touch _ex3.txt
echo Rafail >> _ex3.txt
chmod a-x _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod uo+rwx _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod g=u _ex3.txt
ls -l _ex3.txt >> ex3.txt
echo "660 means that the owner permission is r+w (6 in decimal = 110 in binary, 1 - allow, 0 - prohibits), the group permission r+w (the same) and the other permission is nothing (0 in decimal = 000 in binary, no permission). Total permission is -rw-rw----" >> ex3.txt
echo "775 means that the owner permission is r+w+x (7 in decimal = 111 in binary, 1 - allow, 0 - prohibits), the group permission r+w+x (the same) and the other permission is r+x (5 in decimal = 101 in binary, 1 - allow, 0 - prohibits). Total permissions is -rwxrwxr-x" >> ex3.txt
echo "777 seem that for owner, group and others allowed to read, write and execute. Total permissions is -rwxrwxrwx" >> ex3.txt
