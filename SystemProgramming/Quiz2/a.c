#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {

  printf("Argc = %d\n", argc);
  fflush(stdout);
  if (argc < 3) {
    printf("No arguments passed");
    exit(-1);
  }

  int n = atoi(argv[1]);
  printf("n=%d\n", n);
  fflush(stdout);

  if (argc != n + 3) {
    printf("Not enough arguments");
    exit(-1);
  }

  int* a = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    a[i] = atoi(argv[i + 2]);

  for (int i = 0; i < n + 3; i++)
    printf("%s ", argv[i]);
  printf("\n");
  fflush(stdout);

  int pid, is_sorted = atoi(argv[n + 2]);

  switch (pid = fork()) {
    case -1:
      printf("Error\n");
      exit(-1);
    case 0: {
              if (is_sorted) {
                int l = 0, r = n, x = 3;
                while (r - l > 1) {
                  int m = l + r >> 1;
                  if (a[m] > x)
                    r = m;
                  else
                    l = m;
                }
                if (a[l] == x)
                  printf("There is %d in the array", x);
                else
                  printf("There is no number %d in the array", x);
                fflush(stdout);
              }
            }
    default: {
               if (!is_sorted) {
                  for (int i = 0; i < n; i++)
                    for (int j = 0; j < n - 1; j++)
                      if (a[j] > a[j + 1]) {
                        int buf = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = buf;
                      }
                  /*
                  char* const args = malloc((n + 4) * sizeof(int));
                  for (int i = 0; i < n + 3; i++)
                    args[i] = malloc(10 * sizeof(char));
                  sprintf(&args[0], "%d", 0);
                  sprintf(&args[1], "%d", n);
                  for (int i = 0; i < n; i++)
                    sprintf(&args[i + 2], "%d", a[i]);
                  printf("\n");
                  fflush(stdout);
                  sprintf(&args[n + 2], "%d", 1);
                  for (int i = 0; i < n + 3; i++)
                    printf("%c ", (args[i + 2]));
                  execve("/Users/nurlan/work/Labs/SystemProgramming/Quiz2/a.out", args, NULL);
                  */
                  char* const args = {"a", "3", "1", "2", "3", "1"};
                  printf("OK");
                  execve("/Users/nurlan/work/Labs/SystemProgramming/Quiz2/a.out",
                    &args
                  , NULL);
                  printf("%d", atoi(argv[2]));
                  int st;
                  wait(&st);
                  exit(0);
               }
             }
  }

}
