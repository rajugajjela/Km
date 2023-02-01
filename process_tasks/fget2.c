#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    char *message;
    int n;
    int exit_code;

    printf("fork program starting");
    pid = fork();
    printf("$$$%d", getpid());
    switch (pid)
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
        exit_code = 0;
        break;
    }
    for (; n > 0; n--)
    {
        puts(message);
        sleep(1);
    }
    if (pid != 0)
    {
        int stat_val;
        pid_t child_pid;
        child_pid = wait(&stat_val);
        printf("%d %d", stat_val, &stat_val);
        printf("child has finished :PID=%d\n", child_pid);

        if (WIFEXITED(stat_val))
            printf("child exited with code  %d\n", WEXITSTATUS(stat_val));
        else
            printf("child terminated abnormally\n");
    }
    exit(exit_code);
}