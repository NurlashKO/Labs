#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int st;
int b[1000];

int main() {
  int result = 0, ch_pid, pid, ans = 0;

  switch (pid = fork()) {
    case -1:
      printf("Error\n");
      exit(-1);
    case 0: {
              switch (ch_pid = fork()) {
                case 0:
                  printf("New child parent ID is %d\n", getppid());
                  fflush(stdout);
                  sleep(2);
                  printf("Child parent ID after some delay %d\n", getppid());
                  fflush(stdout);
                  sleep(6);
                  fflush(stdout);
                  printf("Child parent ID after some delay %d\n", getppid());
                  exit(0);
                default:
                  printf("Parent ID : %d\n", getpid());
                  fflush(stdout);
                  sleep(1);
                  printf("Parent have benn killed\n");
                  fflush(stdout);
                  exit(0);
              }
              exit(0);

            }
    default :
            printf("Grand parent ID : %d\n", getpid());
            fflush(stdout);
            sleep(5);
            wait(&st);

  }
}
