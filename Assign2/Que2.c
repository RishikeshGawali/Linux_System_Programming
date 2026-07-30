#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    printf("Appliaction name is:%s\n",argv[1]);

    int fd = 0;
    char Buffer[BLOCKSIZE];

    if(argc != 2)
    {
        printf("Insuffecient arguments...\n");
        return -1;
    }

    fd = open(argv[1],O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open the file...\n");
        return 0;
    }

    scanf("%s",&Buffer);

    write(fd,Buffer,BLOCKSIZE);

    close(fd);

    return 0;
}
