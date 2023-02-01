#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int MAX = 100, i = 0;
pthread_mutex_t mutex;

void *EvenNum()
{

    for (; i < MAX;)
    {
        pthread_mutex_lock(&mutex);

        if (i % 2 == 0)
        {

            printf("%d ", i);
            i++;
        }
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(0);
}
void *OddNum()
{

    for (; i < MAX;)
    {
        pthread_mutex_lock(&mutex);

        if (i % 2 != 0)
        {

            printf("%d ", i);
            i++;
        }
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(0);
}
int main()
{
    pthread_t thread1, thread2;
    pthread_mutex_init(&mutex, NULL);
    if (pthread_create(&thread1, NULL, &EvenNum, NULL) != 0)
    {
        return 1;
    }
    if (pthread_create(&thread2, NULL, &OddNum, NULL) != 0)
    {
        return 2;
    }
    if (pthread_join(thread1, NULL) != 0)
    {
        return 3;
    }
    if (pthread_join(thread2, NULL) != 0)
    {
        return 5;
    }
    pthread_mutex_destroy(&mutex);

    return 0;
}