#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>

int main(){
    int file=0;

    // Opening the file "test.txt" in read-only mode
    if((file=open("test.txt", O_RDONLY))< -1)
        return -1;

    char buffer[19];

    // Reading up to 19 characters from the file into the buffer
    if(read(file, buffer, 19)) return 1;

    // Printing the contents of the buffer as a string
    printf("%s\n", buffer);

    // Moving the file pointer to the 10th byte from the beginning of the file
    if(lseek(file, 10, SEEK_SET) < 0) return 1;

    // Reading up to 19 characters from the new position in the file into the buffer
    if(read(file, buffer, 19) != 19) return 1;

    // Printing the contents of the buffer as a string
    printf("%s\n", buffer);

    // Closing the file
    close(file);

    return 0;
}
