/*
    Write a program which accept two file names from user and 
    copy the contents of an existing file into newly created file.

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char* argv[])
{
    int fdSource=0, fdDest=0;

    char old[20] = {'\0'};
    char new[20] = {'\0'};
    char Buffer[BLOCKSIZE] = {'\0'};
    int Ret = 0;

    printf("Enter the Existing file name  :\n");
    scanf("%s",&old);

    printf("Enter the new file name that you wants to create \n");
    scanf("%s",&new);

    fdSource = open(old,O_RDWR);    

    if(fdSource == -1)
    {
        printf("File not exist\n");
    }
    else
    {
        printf("File is successfully opened\n");
    }

    fdDest = creat(new,0777);

    if(fdDest != -1)
    {
        printf("File is successfully created\n");
    }
    else    
    {
        printf("Unable to create file\n");
        close(fdSource);
        return -1;
    }

    while((Ret = read(fdSource,Buffer,sizeof(Buffer))) != 0)
    {
        write(fdDest,Buffer,Ret);
        memset(Buffer,0,sizeof(Buffer));    
    }
    
    return 0;
}