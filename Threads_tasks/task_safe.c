#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_func()
{
  printf("HI\n");
}

void *thread_func2()
{
  printf("Hello\n");
}

int main()
{
  pthread_t tid0 = 1;
  pthread_t tid1 = 2;
  pthread_create(&tid0, NULL, thread_func, (void *)&tid0);
  sleep(1);
  pthread_create(&tid1, NULL, thread_func2, (void *)&tid1);
  pthread_exit(NULL);
  return 0;
}