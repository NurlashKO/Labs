#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

  if((childpid = fork()) == -1)
  {
          perror("fork");
          exit(1);
  }

  if (childpid == 0) {
    FILE *f = fopen("input.txt", "r");
    fscanf();
  }

}
