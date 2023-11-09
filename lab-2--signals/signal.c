/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile int flag = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  flag = 1;
  // This is a simple but effective way to have a function execute periodically in a C program
  alarm(1);
  // If this line were to be uncommented and included in the handler function, the program would terminate the first time the signal handler is invoked, effectively breaking the recurring alarm setup.
  //exit(1); //exit after printing
}


int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 1 second

  while (1)
  {
    while (flag == 0); // Busy wait for signal to be delivered
    printf("Turing was right!\n");
    flag = 0; // Reset flag
  }
  return 0; // Never reached, unless you include an exit condition
}
