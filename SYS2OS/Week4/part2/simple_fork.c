#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  printf("Simple fork example program\n");

  pid_t main_pid = getpid();
  pid_t fork_pid = fork();

  if (fork_pid == -1) {
    perror("Fork() failed");
    return 1;
  }

  printf("Fork return value: %d\n", fork_pid);
  usleep(1);
  printf("Main process PID: %d\n", main_pid);
  usleep(1);
  printf("Current process PID: %d\n", getpid());
  usleep(1);
  printf("Current process PPID: %d\n", getppid());
  usleep(1);

  if (fork_pid == 0) {
    printf("This block is only executed by the child process\n");
  }
  else {
    printf("This block is only executed by the parent process\n");

    pid_t terminated_pid = wait(NULL);
    printf("Child process %d terminated\n", terminated_pid);
  }

  return 0;
}

