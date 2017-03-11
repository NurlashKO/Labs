#include <errno.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

char* task1() {
  // test.txt contains hello world
  int rd = open("test.txt", O_APPEND);
  int wr = open("test_wr.txt", O_APPEND);
  int nread;
  char buf[1024];

  while ((nread = read(rd, buf, sizeof buf)) != 0)
  {
      char *out_ptr = buf;
      write(wr, out_ptr, nread);
  }

  close(rd);
  close(wr);
  return "NO, we cannot write data using only O_APPEND flag";
}

char* task2() {
  // test.txt contains hello world
  int rd = open("test.txt", O_APPEND);
  int nread;
  char buf[1024];

  lseek(rd, 3, SEEK_SET);
  while ((nread = read(rd, buf, sizeof buf)) != 0)
  {
      char *out_ptr = buf;
      printf("%s", buf);
  }

  close(rd);
  return "YES";
}

char* task3() {
  int wr = open("test.txt", O_WRONLY);
  int nread;
  char* buf = "CHANGED";

  lseek(wr, 3, SEEK_SET);
  write(wr, buf, 7);

  close(wr);
  return "YES, at least using writing.";
}

int main() {
  printf("Variant C\n");
  printf("Is it possible to read and write using only O_APPEND flag : %s\n", task1());
  printf("Is it possible to read from arbitrary position in the file using lseek() : %s\n", task2());
  printf("Is it possible to use lseek to change data in arbitrary position : %s\n", task3());
}
