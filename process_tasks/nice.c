#include <stdio.h>
#include <sys/resource.h>

int my_nice(int incr)
{
    int prio = getpriority(PRIO_PROCESS, 0);
    if (setpriority(PRIO_PROCESS, 0, prio + incr) == -1)
        return -1;

    prio = getpriority(PRIO_PROCESS, 0);
    return prio;
}

int main(void)
{
    int prio = getpriority(PRIO_PROCESS, 0);
    printf("Current priority = %d\n", prio);

    printf("\nAdding +5 to the priority\n");
    my_nice(5);
    prio = getpriority(PRIO_PROCESS, 0);
    printf("Current priority = %d\n", prio);

    printf("\nAdding -7 to the priority\n");
    my_nice(-7);
    prio = getpriority(PRIO_PROCESS, 0);
    printf("Current priority = %d\n", prio);

    return 0;
}  
