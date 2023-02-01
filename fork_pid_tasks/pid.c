#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main(){
	printf("My PID:%d\n",getpid());
	printf("Parent PID:%d\n",getppid());
	}
