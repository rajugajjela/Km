//server socket program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>


#define PORT 4545
int count=0;
int client;
int main(){

	int sockfd, ret,buffer1[1025];
	struct sockaddr_in serverAddr;

	socklen_t addr_size;

	int newsocket;
	struct sockaddr_in newAddr;

	char buffer[1024];
	pid_t childpid;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		printf("error in connection..\n");
		exit(1);
	}
	printf("server socket is created..\n");


	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("error in binding.\n");
		exit(1);
	}
	printf("bind to port %d\n",PORT);
        if(listen(sockfd, 10)==0){
		printf("listening..\n");
	}
	else
	{
		printf("error in binding..\n");
	}
	while(1){
		newsocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
		if(newsocket < 0){
			exit(1);
		}
		printf("connection accepted from %s:%d\n",inet_ntoa(newAddr.sin_addr),ntohs(newAddr.sin_port));

		printf("client : %d\n",count++);
		{
			switch(count)
			{
				case 0:printf("from client 0");

				        break;     

				case 1: printf("client 1");
				      
				        break;
				case 2: printf("client 2");

				        break;

				default: printf("multiple client connections..\n");

				        break;
			}
		}		

		if((childpid = fork()) ==0){
			printf("pid =%d\n",getpid());
			close(sockfd);
			while(1){
				bzero(buffer,sizeof(buffer));
			        read(newsocket,buffer,sizeof(buffer));	
					for(int i=0; buffer[i]!='\0'; i++)
{
					if(buffer[i] >='a' && buffer[i] <='z')
					{
						buffer[i] = buffer[i] -32;
					}
					else if(buffer[i]>='A' && buffer[i]<='Z')
					{
						buffer[i] = buffer[i]+32;
					}                            
}
				printf(" To server %s \t",buffer);
				bzero(buffer,sizeof(buffer));
				int n=0;
				while((buffer[n++]=getchar())!='\n');
                                write(newsocket,buffer,sizeof(buffer));

			}
		}
	}
	close(newsocket);
	 
	return 0;
}
