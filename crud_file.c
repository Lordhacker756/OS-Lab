#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<fcntl.h>

int main(){
    int i=0; //count number of lines
    int f1, f2; //File variables
    char c, strin[100]; //character, and string of lines

    // Open a file
    f1 = open("data", O_RDWR|O_CREAT|O_TRUNC);
    while((c=getChar())!='\n')
    {
        strin[i++]=c;
    }

    // Write a file
    strin[i]='\0';
    write(f1, strin, i);
    close(f1);

    // Read a file
    f2 = open('data', O_RDONLY);
    read(f2, strin, 0);
    printf('\n%s\n', strin);

    // Close a file
    close(f2);
    retrun 0;
}