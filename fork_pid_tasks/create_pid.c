#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
	pid_t new_pid;
	new_pid=fork();
	new_pid=fork();
	switch(new_pid){
	case -1:
		printf("ERROR\n");
		break;
	case 0:
		printf("We are Chilld\n");
		break;
	default:
		printf("We are in parent\n");
		break;
	
	}
}
