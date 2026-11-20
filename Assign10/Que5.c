/////////////////////////////////////////////////////////////////////////////
//Write a program which is used to get thread id insice its thread function.
/////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include <sys/wait.h>
#include<pthread.h>

void* ThreadProc(void* ptr)
{
    //pthread_t thId = pthread_self();
   printf("From ThreadProc : Thread id of Newly created thread is : %ld\n",(pthread_t*)pthread_self());
}


int main()
{

    pthread_t TID;
    int ret=0;
    int Result=0;

    printf("Thread id of Main thread is : %ld\n",(pthread_t *)pthread_self());

    ret=pthread_create(&TID,NULL,ThreadProc,NULL);
    if(ret!=0)
    {
        printf("Thread is not created...");
    }

    printf("From Main : Thread created Successfully with id : %ld\n",TID);
    
    pthread_join(TID,NULL);
    
    return 0;
}