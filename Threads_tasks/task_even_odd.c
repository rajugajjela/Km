#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int MAX = 100, i = 0;

void *printEvenNum()
{

    for (; i < MAX;)
    {
        if (i % 2 == 0)
        {
            printf("%d ", i);
            i++;
        }
    }
    pthread_exit(0);
}
void *printOddNum()
{
    for (; i < MAX;)
    {
        if (i % 2 != 0)
        {
            printf("%d ", i);
            i++;
        }
    }

    pthread_exit(0);
}
int main()
{
    pthread_t thread1;
    pthread_t thread2;
    if (pthread_create(&thread1, NULL, &printEvenNum, NULL) != 0)
    {
        return 1;
    }
    if (pthread_create(&thread2, NULL, &printOddNum, NULL) != 0)
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

    return 0;
}