#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int sum = 0; // This data is shared by the thread(s)

// Thread 1 will execute this function
void *increment(void *param) {
    int limit = atoi(param);
    for (int i = 1; i <= limit; i++) {
        sum += 1;
        // printf("counter: %d, sum: %d\n", i, sum);
    }
    // sleep(60);
    // printf("Child-1 PID: %d\n", getpid());
    // printf("Child-1 Thread ID: %lu\n", pthread_self());
    pthread_exit(0);
}

// Thread 2 will execute this function
void *decrement(void *param) {
    int limit = atoi(param);
    for (int i = 1; i <= limit; i++) {
        sum -= 1;
    }
    // sleep(60);
    // printf("Child-2 PID: %d\n", getpid());
    // printf("Child-2 Thread ID: %lu\n", pthread_self());
    pthread_exit(0);
}


int main(int argc, char *argv[]) {
    pthread_t tid1, tid2; // Thread identifiers
    int return_status;

    printf("Main PID: %d\n", getpid());

    if (argc < 2) {
        printf("Invalid input arguments\n");
        exit(0);
    }

    // Create first thread
    return_status = pthread_create(&tid1, NULL, increment, argv[1]);
    if (return_status != 0) {
        perror("First thread creation failed");
        exit(1);
    }
    // Create second thread
    return_status = pthread_create(&tid2, NULL, decrement, argv[1]);
    if (return_status != 0) {
        perror("Second thread creation failed");
        exit(1);
    }

    // Wait for the threads to exit; pthread_join blocks the calling thread
    // until the specified thread terminates.
    return_status = pthread_join(tid1, NULL);
    if (return_status != 0) {
        perror("Thread join failed");
        exit(1);
    }
    return_status = pthread_join(tid2, NULL);
    if (return_status != 0) {
        perror("Thread join failed");
        exit(1);
    }

    printf("sum = %d\n", sum);
    return 0;
}


