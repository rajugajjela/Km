// client program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define PORT 4545

int main(){

	int clientsocket,ret;
	struct sockaddr_in cliAddr,serverAddr;
	char buffer[1024];

	clientsocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientsocket < 0){
		printf("error in connection..\n");
		exit(1);
	}
	printf("client socket is created..\n");
        //Initializing socket struct with NULL
	//Initializing buffer array with NULL
	memset(&cliAddr, '\0', sizeof(buffer));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = connect(clientsocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("error in connection...\n");
		exit(1);
	}
	printf("connect to server..\n");

	while(1)
	{
	        bzero(buffer, sizeof(buffer));
		printf("To server:\t");
		int n=0;
		while((buffer[n++]=getchar())!= '\n');
		write(clientsocket,buffer,sizeof(buffer));
	         read(clientsocket, buffer,sizeof(buffer));
                 printf("server: \t%s\n",buffer);
	}


	return 0;
}


