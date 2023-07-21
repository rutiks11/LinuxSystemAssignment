/*
    Assignment 1_4
    Write a program which accept file name and print all
    information about that file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    struct stat sobj;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    stat(argv[1],&sobj);

    printf("File name : %s\n",argv[1]);
    printf("File size is : %d\n",sobj.st_size);
    printf("Number of links : %d\n",sobj.st_nlink);
    printf("Inode number : %d\n",sobj.st_ino);
    printf("File system number : %d\n",sobj.st_dev);
    printf("Number of blocks : %d\n",sobj.st_blocks);
    printf("Permissions of File : %d\n",sobj.st_mode);
    printf("Recent Time %ld\n",sobj.st_atime);
    printf("Recent Modification time %ld\n",sobj.st_mtime);
    printf("Blocks used by File %ld\n",sobj.st_blksize);

    return 0;
}