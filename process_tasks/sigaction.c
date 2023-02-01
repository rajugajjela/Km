#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void new_action(int signum)
{
    printf("\n Hey I got the signal %d", signum);
    sleep(10);
    printf("done\n");
}

int main(){
    struct sigaction action;
    
    action.sa_handler = &new_action;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    if(sigaction(SIGINT,&action,NULL)==-1)
    {
        printf("sigaction fail\n");
        exit(1);
    }
    while(1){
        printf("Hello world\n");
        sleep(1);
    }
}