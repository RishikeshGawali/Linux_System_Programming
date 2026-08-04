////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Write a program which creates two processes can communicate with each other by using concept of shared memory.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include <sys/wait.h>

int main()
{
    int Ret1=0,Ret2=0;
    int cpid=0,Exit_Status=0;


    Ret1 = fork();

    if (Ret1 == 0)
    {
        printf("Process 1 is Running...\n");
        execl("./Process1","NULL",NULL);   

        printf("Process 1 Terminated...\n");
    }

    Ret2 = fork();

    if (Ret2 == 0)
    {
        printf("Process 2 is Running...\n");
        execl("./Process2","NULL",NULL);   

        printf("Process 2 Terminated...\n");
    }
    
    else
    {
        printf("Parent Process is Running...\n");
        cpid = wait(&Exit_Status);
       
        printf("\n");
        printf("Parent Terminates...\n");
    }
    
    

    return 0;
}