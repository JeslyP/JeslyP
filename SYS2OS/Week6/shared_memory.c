#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <unistd.h>

#define SHARE_NAME "Shared"
#define SHARE_SIZE 4096

int main() {
    const char *message_0 = "Hello ";
    const char *message_1 = "I am a shared message";

    // Create a file descriptor for a shared object with the given name
    int shm_fd = shm_open(SHARE_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SHARE_SIZE);

    char *ptr = mmap(0, SHARE_SIZE, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    sprintf(ptr, "%s", message_0);
    ptr += strlen(message_0);
    sprintf(ptr, "%s", message_1);
    ptr += strlen(message_1);

    pid_t child_return = fork();

    if (child_return == 0) {
        char *ptr1 = mmap(0, SHARE_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
        if (ptr1 == MAP_FAILED) {
            perror("mmap failed");
            return 1;
        }
        printf("%s\n", ptr1);
        munmap(ptr1, SHARE_SIZE);
        shm_unlink(SHARE_NAME);
    }
    munmap(ptr, SHARE_SIZE);

    return 0;
}
