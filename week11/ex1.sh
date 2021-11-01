sudo fallocate -l 50M lofs.img
sudo losetup -f lofs.img
sudo mkfs.ext4 $(losetup -a | grep 'lofs.img' | awk '{print $1}' | rev | cut -c 2- | rev)
mkdir lofsdisk
sudo mount $(losetup -a | grep 'lofs.img' | awk '{print $1}' | rev | cut -c 2- | rev) lofsdisk
