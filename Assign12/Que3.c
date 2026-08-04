////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Write a program which creates one child process , child process write something in unnamed pipe and 
// parent process read data from that pipe.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    int FD[2];
    int Ret=0;
    int cpid=0,Exit_Status=0;
    char Arr[] = "THE LINUX PROGRAMMING INTERFACE , by Michael Kerrisk.";
    char Buffer[200];

    pipe(FD);

    Ret = fork();

    if (Ret == 0)
    {
        close(FD[0]);
        
        printf("Child Process is Running...\n");
        write(FD[1],Arr,strlen(Arr));
        printf("Child Process Writing data in Unnamed pipe is => %s\n\n",Arr);
        
    }
    else
    {
        close(FD[1]);
        
        printf("Parent Process is Running...\n\n");
        cpid = wait(&Exit_Status);
        
        read(FD[0],Buffer,sizeof(Buffer));
        printf("Parent Process read Data from unnamed pipe is => %s\n",Buffer);
        
        exit(0);
    }
    
    

    return 0;
}