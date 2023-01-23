#include <linux/kernel.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define __hamta 548
// asmlinkage long sys_hamta(int pid, char __user *file_path);

int main(int argc, char *argv[])
{
	int pid = 1527;
	long res;
	res = syscall(__hamta, pid, "proc.txt");
	if(res < 0)
	{
		printf("sorry %ld", res);
	}
	else
	{
		printf("hamta WORKED! %ld", res);
	}
	return 0;
}
