#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	int ret,nread,nwrite,fd;
	char buff[100];
	
	fd=open("abc",O_RDONLY);
	printf("open system call return value:%d\n",fd);
	if(fd<0){
	perror("error\n");
	}
	
	nread=read(fd,&buff,100);
	printf("read ret value:%d\n",nread);
	if(nread<0){
	perror("error\n");
	}
	
	ret=lseek(fd,10,SEEK_SET);
	printf("lseek ret return:%d\n",ret);
	
	nwrite=write(fd,"kernel",10);
	printf("write return:%d\n",write);
	
	close(fd);
}
