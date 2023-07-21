/*
    Write a application which accept directory name from user and create new directory
	of that name.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int fd =0;

    fd = mkdir(argv[1],0777);

    if(fd==-1)
    {
        printf("Directory is not created\n");
    }
    else
    {
        printf("Directory successfylly created\n");
    }
    return 0;
}