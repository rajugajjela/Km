#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>

int main()
{
    printf("My PID:%d\n", getpid());
    sleep(5);
    kill(getpid(), SIGKILL);
    return 0;
}
