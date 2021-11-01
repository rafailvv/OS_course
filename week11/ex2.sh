sudo echo Rafail >> ./lofsdisk/file1.txt
sudo echo Venediktov >> ./lofsdisk/file2.txt
gcc ex2.c -o ex2
./ex2
sudo mkdir lofsdisk/lib
sudo mkdir lofsdisk/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libtinfo.so.6 lofsdisk/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libdl.so.2 lofsdisk/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libc.so.6 lofsdisk/lib/x86_64-linux-gnu
sudo mkdir lofsdisk/lib64
sudo cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64/
sudo cp /lib/x86_64-linux-gnu/libselinux.so.1 lofsdisk/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libpcre2-8.so.0 lofsdisk/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libpthread.so.0 lofsdisk/lib/x86_64-linux-gnu
sudo cp /bin/bash lofsdisk/bin/
sudo cp /bin/cat lofsdisk/bin/
sudo cp /bin/ls lofsdisk/bin/
cd lofsdisk
sudo cp ..ex2.c ex2.c
sudo gcc ex2.c -o ex2
sudo chroot lofsdisk
./ex2 > ex2.txt
./ex2 >> ex2.txt
