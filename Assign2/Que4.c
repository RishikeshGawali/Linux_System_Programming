#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc , char *argv[])
{
    DIR *dp = NULL;
	struct stat sobj;
    char DirName[20];
    struct dirent *entry = NULL;
    char name[30];

	if(argc != 2)
	{
		printf("Insufficiant number of arguments\n");
		return -1;
	}

	stat(argv[1],&sobj);
    dp = opendir(DirName);

    while((entry = readdir(dp) ) != NULL)
    {
        stat(name,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            printf("Regular : %s\n",name);
        }
        else if(S_ISDIR(sobj.st_mode))
        {
            printf("Directory :%s\n",name);
        }
        else if(S_ISLNK(sobj.st_mode))
        {
            printf("Symbolic Link :%s\n",name);
        }
    }

	return 0;
}
