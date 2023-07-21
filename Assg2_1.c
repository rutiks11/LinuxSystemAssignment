/*
    Write a program which accept file name from 
    user and read whole file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define BLOCKSIZE 1024

int main(int argc, int *argv[])
{
    int fd= 0;
    int Ret= 0;
    char Buffer[BLOCKSIZE] = {'\0'};

    if(argc != 2)
    {
        printf("Inavalid Arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open File\n");
    }
    else
    {
        printf("File is successfully open with fd %d\n",fd);
    }

    while((Ret = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        write(1,Buffer,Ret);
    }

    return 0;
}