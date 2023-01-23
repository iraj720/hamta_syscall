# hamta_syscall

hamta_syscall is a new syscall on kernel 5.8.1 that accepts 2 parameters : pid, file_path\n
it will check whether that pid is running or not (by checking task_list of kernel) 
if it does exist it will return 1
else it will write it on the file_path that you have specified as parameter and return 0


New Syscall added to linux-5.8.1
tested with these following configs :
arch: x86
distro : Ubuntu-20.04
vmbox 7.0

to use this new patch do the following steps : 
1. these packages should be installed : (build-essential libncurses-dev libssl-dev libelf-dev bison flex)
2. wget -P ./ https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.8.1.tar.xz
3. tar -xf linux-5.8.1.tar.xz -C ./
4. cd linux-5.8.1/
5. copy the .config of your own /boot directory or use `make defconfig` or add tested .config from patch file
6. apply all patches
7. make && make modules_install && make install && sudo update-grub 
8. then reboot your machine (sudo shutdown -r now)
9. open test.c and set pid whatever you want (check pids with "ps aux") 
10. test the test.c file with gcc (gcc -o test test.c && sudo ./test)
