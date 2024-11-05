#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define SIZE 80

int main() {
    // Create FIFO (will fail silently if the pipe already exists)
    char *mypipe = "/tmp/mypipe";
    int ret = mkfifo(mypipe, 0666);

    char wmsg[SIZE], rmsg[SIZE];

    while (1) {
        // Open FIFO for write only
        int fd = open(mypipe, O_WRONLY);

        //gets the input message from the user from the terminal
        fgets(wmsg, SIZE, stdin);
  
        // Write the input message on FIFO
        // and close it
        write(fd, wmsg, strlen(wmsg)+1);
        close(fd);
  
        // Open FIFO for Read only 
        fd = open(mypipe, O_RDONLY);
  
        // Read from FIFO 
        read(fd, rmsg, sizeof(rmsg));
  
        // Print the read message 
        printf("User2: %s\n", rmsg);
        close(fd);
    }

    return 0;
} 