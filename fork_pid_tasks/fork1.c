#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	pid=fork();
	
	if(pid==-1)
	{
		printf("ERROR");
	}
	
	if(pid==0)
	{
		sleep(1);
		printf("Child:%d",getpid());
		printf("Child Parent:%d",getppid());
	}
	else
	{
		sleep(1);
		printf("parent process pid:%d\n",getpid());
		printf("parent process parent pid:%d\n",getppid());
	}
}
