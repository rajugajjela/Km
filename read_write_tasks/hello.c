#include <unistd.h>
#include <sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


int main()
{
	int fd,ret;
	char buffer[10];
	
	fd=open("abc.txt",O_RDONLY);
	if(fd>0){
	perror("open fails\n");
	printf("errorno:%d\n",errno);
	}
	
	
	ret=read(fd,&buffer,10);
	if(ret<0){
	perror("Read fails:\n");
	printf("errorno:%d\n",errno);
	}
	
	
	write(fd,&buffer,10);
	close(fd);
	fd=open("xyz",O_RDONLY);
	if(fd<0){
	perror("write fails:\n");
	printf("errorno:%d\n",errno);
	}
	
	
	return 0;
}
