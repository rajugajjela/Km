#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
int ret;
char buff[100];
        ret = read(0,&buff,6);
        if (ret < 0)
        {
        perror("Read Fails");
        printf("errno:%d\n",errno);
        return -1;
        }
        printf("ret:%d buff:%s\n",ret,buff);
        return 0;
}

