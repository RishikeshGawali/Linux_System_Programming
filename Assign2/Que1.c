#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

#define BLOCKSIZE 1024
int main(int argc ,char *argv[])
{
    printf("Appliaction name is:%s\n",argv[0]);

    int fd = 0;
    int ret = 0;
    char Buffer[BLOCKSIZE];

    if(argc != 2)
    {
        printf("Invalid arguments...\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file...\n");
        return -1;
    }

    printf("The data of file is :\n");

    while((ret = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        write(1,Buffer,ret);
    }

    close(fd);
    return 0;
}
