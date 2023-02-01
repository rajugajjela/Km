#include<stdio.h>
#include<unistd.h>


char *const pv_argv[]={"ps","eaf",0};

int main()
{
	int ret;
	printf("starting the line\n");
	getchar();
	
	ret=execve("/bin/ps",pv_argv,NULL);
	
	if(ret<0)
	{
		perror("failed");
	}
}
	


