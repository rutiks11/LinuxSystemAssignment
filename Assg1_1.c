/*
    Assignment 1_1
    Write a program which accept file name from user and open that file 
*/

#include<stdio.h>
#include<fcntl.h>

int main(int argc, int *argv[])
{
    int fd  = 0;

    if(argc != 2)
    {
        printf("Invalid Arguments\n");
        return -1;
    }   

    fd = open(argv[1],O_RDONLY);

    if(fd != -1)
    {
        printf("File is successfully opened with fd %d\n",fd);
    }
    else
    {
        printf("Unable to Open File\n");
    }

    return 0;
}
