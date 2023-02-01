/* Producer consumer program using pthreads, Semaphores */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>


void *producer();
void *consumer();
char buffer[26];
sem_t empty,full;

int main() {
    int res;
    pthread_t a_thread,b_thread;
    void *thread_result;
    int print_count1 = 0;
   sem_init(&full, 0, 0);

   sem_init(&empty, 0, 26);

    res = pthread_create(&a_thread, NULL, producer, NULL);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    res = pthread_create(&b_thread, NULL, consumer, NULL);
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

void *producer() {
    int in = 0,value;
    char ch = 'A';
    while(1)
	{
		sem_wait(&empty);
		buffer[in]=ch;
		in = (in+1)% 26;
		if (in == 0)
		{
		printf("P:%s\n",buffer);
		ch = 'A';
		}
		else
		ch++;
		sem_post(&full);
	}
	
   pthread_exit("exit");	
}
void *consumer() {
    int out = 0, value;
    char buf[26];
    while(1)
	{
		sem_wait(&full);		
		buf[out] = buffer[out];
		out = (out+1)% 26;
		if (out == 0)
		printf("\tC:%s\n",buf);
		
		sem_post(&empty);
	}
   pthread_exit("exit");	
}