#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main(){

	fork();
	printf("My pid=%d\n", getpid());
   	printf("Parent's pid=%d\n", getppid());
	getchar();
	return(0);
}
