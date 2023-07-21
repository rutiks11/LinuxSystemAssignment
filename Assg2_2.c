/*
    Write a program which accept file name from 
    user and write string in tht file.
*/


#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int main(int argc, int *argv[])
{
    int fd  = 0;
    int iRet  =0;
    char Buffer[BLOCKSIZE] = {'\0'};

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

    printf("Enter string that you want to write : ");
    scanf("%[^\n]s",Buffer);

    iRet = write(fd,Buffer,strlen(Buffer));
    printf("%d bytes gets successfully written in the file",iRet);

    return 0;
}