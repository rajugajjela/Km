#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int MAX = 100000;
// volatile int count = 0;
//pthread_mutex_t mutex;

void *EvenNum()
{
    //pthread_mutex_lock(&mutex);

    // while (count < MAX)
    // {
    //     printf("%d ", count++);
    // }
    for (int i = 0; i < MAX; i++)
    {
        if (i % 2 == 0)
        {
            printf("this is from even %d\n",i);
            sleep(1);
        }
    }
   //pthread_mutex_unlock(&mutex);

    pthread_exit(0);
}
void *OddNum()
{
    //pthread_mutex_lock(&mutex);
    // while (count < MAX)
    // {
    //     printf("%d ", count++);
    // }
    for (int j = 0; j < MAX; j++)
    {
        if (j % 2 != 0)
        {
            printf("this is from odd %d\n",j);
            sleep(1);
        }
    }
   // pthread_mutex_unlock(&mutex);

    pthread_exit(0);
}
int main()
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_create(&thread1, NULL, &EvenNum, NULL);
    pthread_create(&thread2, NULL, &OddNum, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    //pthread_mutex_destroy(&mutex);

    return 0;
}
