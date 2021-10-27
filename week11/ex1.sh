#!/bin/bash
sudo fallocate -l 50M lofs.img
sudo losetup -f lofs.img
sudo mkfs.ext4 $(losetup -a | grep 'lofs.img' | awk '{print $1}' | cut -d ':' -f 1)
mkdir lofsdisk
sudo mount $(losetup -a | grep 'lofs.img' | awk '{print $1}' | cut -d ':' -f 1) ./lofsdisk
ls
cd lofsdisk
ls
cd ..
chmod 777 lofsdisk/
sudo chmod 777 lofsdisk/
sudo echo 1 > lofsdisk/file1
sudo echo 2 > lofsdisk/file1
ls -l lofsdisk/
echo 1 > lofsdisk/file2
ls -l lofsdisk/
df -H
