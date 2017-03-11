#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int st;
int b[1000];

int main() {
  int result = 0, ch_pid, pid[10], ans = 0;
  b[111] = 1;

  for (int i = 0; i < 10; i++) {

    switch(pid[i] = fork()) {
      case 0: {
        int dead = 0;
        for (int j = 0; j < 1000; j++)
          if (j >> i & 1)
            dead |= b[j];
        exit(dead);
      }
      default:
        waitpid(pid[i], &st, 0);
        if (st > 0) ans ^= 1 << i;
    }
  }

  printf("%d", ans);
}
