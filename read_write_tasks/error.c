#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

fd = open("abc",O_RDWR);
printf("open system call return value:%d\n",fd);
if(fd < 0)
{
perror("Open FAILS\n");
exit(0);
}




