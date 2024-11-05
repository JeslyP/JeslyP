#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 100
#define READ_END 0
#define WRITE_END 1

int main(void) {
    int fd[2];
    pid_t pid;

    // Create the pipe
    if (pipe(fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    // Fork a child process
    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    // Parent Process
    if (pid > 0) {
        char write_msg[BUFFER_SIZE] = "Greetings";

        // Close the unused end of the pipe
        close(fd[READ_END]);

        // Write a message to the pipe
        write(fd[WRITE_END], write_msg, strlen(write_msg)+1);

        // Close the write end of the pipe
        close(fd[WRITE_END]);
    }
    // Child Process
    else {
        char read_msg[BUFFER_SIZE] = "";

        // Close the unused end of the pipe
        close(fd[WRITE_END]);

        // Read and print from the pipe
        ssize_t k = read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("read %s\n", read_msg);

        // Close the read end of the pipe
        close(fd[READ_END]);
    }

    return 0;
}