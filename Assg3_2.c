/*
    Write a program which accept directory name and file name from
    user and check whether that file is present in that directory or not

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<stdbool.h>

int main(int argc,char *argv[])
{   
    DIR *dp = NULL;                     // Pointer to catch return value opendir
    struct dirent *entry = NULL;       // Pointer of dirent structure
    char DirName[20];                   // For Directory name
    char name[30];                      
    struct stat sobj;
    char filesearch[30] = {'\0'};
    bool flag = false;
    
    printf("Enter name of Directory : \n");
    scanf("%s",DirName);

    printf("Enter name of File to serach : \n");
    scanf("%s",filesearch);


    dp = opendir(DirName);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        stat(name,&sobj);
        strcpy(name,entry->d_name);
        
        if(strcmp(name,filesearch) == 0)
        {
           flag = true;
           break; 
        }
    }

    if(flag == true)
    {
        printf("File is present in Directory\n");
    }
    else
    {
        printf("File is not present in Directory\n");
    }

    closedir(dp);

    return 0;   
}

