#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

int main() {

  // Seed the random number generator
  srandom(time(NULL));
  pid_t pid1, pid2;
  
  // Create first child process
  pid1 = fork();

  if (pid1 == 0) {
    // Child process 1
    int n = (random() % 30) + 1;
    int i;
    for (i = 0; i < n; i++) {
      printf("Child Pid: %d is going to sleep!\n", getpid());
      sleep(random() % 10);
      printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", getpid(), getppid());
    }
  exit(0);
  }
    
  // Create second child process
  pid2 = fork();
  if (pid2 == 0) {
    // Child process 2
    int n = (random() % 30) + 1;
    int i;
    for (i = 0; i < n; i++) {
      printf("Child Pid: %d is going to sleep!\n", getpid());
      sleep(random() % 10);
      printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", getpid(), getppid());
    }
  exit(0);
  }

  // Parent process
  int status;
  waitpid(pid1, &status, 0);
  printf("Child Pid: %d has completed\n", pid1);
    
  waitpid(pid2, &status, 0);
  printf("Child Pid: %d has completed\n", pid2);
  return 0;
}
