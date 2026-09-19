#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t signal_count = 0;

void handle_signint(int sig) {
  signal_count++;

  if (signal_count == 3) {
    printf("\nProgramme Terminated\n");
    exit(0);
  }

  printf("\nSignal Received, signal count:%d", signal_count);

  printf("\nPress Ctrl+C 3 times to terminate the programme");

}

int main() {
  signal(SIGINT, handle_signint);

  printf("\nThe process is running with (PID: %d), try pressing Ctrl+c...", getpid());

  while(1) {
    sleep(1);
  }

  return 0;
}