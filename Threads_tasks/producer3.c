/* Producer consumer program using pthreads, Semaphores and mutex*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>


void *producer1();
void *producer2();
void *consumer();
char buffer[5];
sem_t empty,full;
pthread_mutex_t prod,cons;

int main() {
    int res,i;
    pthread_t a_thread,b_thread,c_thread;
    void *thread_result;
    int print_count1 = 0;
   sem_init(&full, 0, 0);

   sem_init(&empty, 0, 5);

    res = pthread_create(&a_thread, NULL, producer1, NULL );
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    res = pthread_create(&b_thread, NULL, producer2, NULL );
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    res = pthread_create(&c_thread, NULL, consumer, NULL);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    printf("Wait for pthread_join\n");
    res = pthread_join(a_thread, &thread_result);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    res = pthread_join(b_thread, &thread_result);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    printf("Thread joined\n");
    exit(EXIT_SUCCESS);
}

void *producer1() {
    int in = 0,value;
    char ch='A';
    while(1)
	{
		sem_wait(&empty);

      		pthread_mutex_lock(&prod);
		buffer[in]=ch;
		in = (in+1)% 5;
		ch++;
		if (in == 0)
		{
			ch='A';
			printf("p1:%s\n",buffer);
		}
      		pthread_mutex_unlock(&prod);

		sem_post(&full);
	}
	
   pthread_exit("exit");	
}

void *producer2() {
    int in = 0,value;
    char ch='a';
    while(1)
	{
		sem_wait(&empty);
      		pthread_mutex_lock(&prod);
		buffer[in]=ch;
		in = (in+1)% 5;
		ch++;
		if (in == 0)
		{
			ch='a';
			printf("p2:%s\n",buffer);
		}
      		pthread_mutex_unlock(&prod);

		sem_post(&full);
	}
	
   pthread_exit("exit");
}	
void *consumer()  {
    int out = 0, value;
    char temp[5];
    while(1)
	{
		sem_wait(&full);
      		pthread_mutex_lock(&prod);
		temp[out] = buffer[out];
		out = (out+1)% 5;
		if (out == 0)
		{
		printf("\t%s\n",temp);
		}
      		pthread_mutex_unlock(&prod);
		sem_post(&empty);
	}
   pthread_exit("exit");	
}