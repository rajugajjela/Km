#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	pid_t pid;
	
	pid=fork();
	
	if(pid==0)
	{
		execl("/bin/ls","ls",NULL);
	}
	else
	{
		wait(NULL);
		printf("Child Complete");
		exit(0);
	}
}
