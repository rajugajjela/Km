#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include <pthread.h>
#include <semaphore.h>


#define PORT 4545
int count=0;
int client;
int main(){

	sem_t x, y;
	pthread_t tid;
	pthread_t writerthreads[100];
	pthread_t readerthreads[100];
	int readercount = 0;
	
	           
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
	printf("The server socket is created..\n");


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

		int choice=0;
		recv(newsocket,&choice,sizeof(choice),0);
		
		if(choice==1){
			if(pthread_create(&writerthread[i++],NULL,reader,&newsocket)!=0)
			{
				printf("failed to create");
			}
		else if (choice == 2) {
            // Create writers thread
        	    if (pthread_create(&writerthreads[i++], NULL,
        	                       writer, &newsocket)
        	        != 0)
 
                // Error in creating thread
        	        printf("Failed to create thread\n");
        	}
 	
        	if (i >= 50) {
        	    // Update i
        	    i = 0;
 	
        	    while (i < 50) {
        	        // Suspend execution of
        	        // the calling thread
        	        // until the target
        	        // thread terminates
        	        pthread_join(writerthreads[i++],
        	                     NULL);
        	        pthread_join(readerthreads[i++],
        	                     NULL);
        	    }
 	
        	    // Update i
        	    i = 0;
        	}
//		printf("client : %d\n",count++);
//		{
//			switch(count)
//			{
//				case 0:printf("from client-0");
//
//				        break;
//				     

//				case 1: printf("client-1");
				      
//				        break;
//				case 2: printf("client-2");
//
//				        break;

//				default: printf("multiple client connections..\n");

//				        break;
//			}
//		}		
			if((childpid = fork()) ==0){

			printf("pid =%d\n",getpid());
			close(sockfd);

			while(1){

			


				bzero(buffer,sizeof(buffer));


				//recv(newsocket, buffer,1024,0);
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
