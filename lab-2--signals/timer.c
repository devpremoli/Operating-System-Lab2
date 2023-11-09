#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

volatile int flag = 0;
volatile int count = 0;

void alarm_handler(int signum) {
  printf("Hello World!\n");
  flag = 1;
  count++;
  alarm(1);
}

void int_handler(int signum) {
  printf("Total time: %d seconds\n", count);
  exit(0);
}

int main() {
  signal(SIGALRM, alarm_handler);
  signal(SIGINT, int_handler);
  alarm(1);

  while(1) {
    if(flag == 1) {
      printf("Turing was right!\n");
      flag = 0;
    }
  }
  return 0;
}
