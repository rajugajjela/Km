#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
    pid_t pid;
    char *message;
    int n;

    printf("fork program starting");
    pid = fork();
    printf("$$$%d", getpid());
    switch(pid)
    {
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
            message = "This is the child";
            printf("child pid=%d child ppid=%d\n", getpid(), getppid());
            n = 5;
            break;
        default:
            message = "This is the parent";
            printf("Parent pid=%d Parent ppid=%d\n", getpid(), getppid());
            n = 3;
            break;
        }
        for (;n > 0; n--){
            puts(message);
            sleep(1);
        }
        exit(0);
}