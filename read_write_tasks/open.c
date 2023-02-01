#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc,char *argv[]){

	int fd,nread,nwrite,ret;
	char buff[10];
	
	printf("argv[0]:%s\n",argv[0]);
	printf("argv[1]:%s\n",argv[1]);
	
	fd=open(argv[1],O_RDONLY);
	printf("fd returns:%d\n",fd);
	if(fd<0){
		printf("error\n");
		exit(0);
	}
	
	nread=read(fd,&buff,100);
	printf("nread return:%d\n",nread);
	if(nread<0){
		perror("error\n");
	}
	
	
	while(0!=nread)
	{
		nwrite=write(1,&buff,nread);
		nread=read(fd,&buff,100);
	}
	ret=close(fd);
	if(ret<0){
		perror("error");
		exit(0);
	}
}		

