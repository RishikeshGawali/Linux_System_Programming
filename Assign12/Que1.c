////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Write a Program which is used to create unnamed pipe. Parent Process creates new child process and both the 
// Processes will communicate with each other.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int FD[2];
    int Ret=0;
    char Arr[] = "THE LINUX PROGRAMMING INTERFACE , by Michael Kerrisk.";
    char Buffer[200];

    pipe(FD);

    Ret = fork();

    if (Ret == 0)
    {
        //close(FD[1]);
        printf("Child Process is Running...\n");
        read(FD[0],Buffer,sizeof(Buffer));
        printf("Child Process read Data from unnamed pipe is => %s\n",Buffer);
    }
    else
    {
        //close(FD[0]);
        printf("Parent Process is Running...\n");
        write(FD[1],Arr,strlen(Arr));
        printf("Parent Process Writing data in Unnamed pipe is => %s\n\n",Arr);
        exit(0);
    }
    
    

    return 0;
}