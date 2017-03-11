#include <errno.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int cp(const char* from, const char* to) {
  int fd_to, fd_from;
  char buf[4096];
  ssize_t nread;
  int saved_errno;

  fd_from = open(from, O_RDONLY);
  if (fd_from < 0)
      return -1;

  fd_to = open(to, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
  if (fd_to < 0)
    return -1;

  while ((nread = read(fd_from, buf, sizeof buf)) != 0)
  {
      char *out_ptr = buf;
      ssize_t nwritten;

      do {
          nwritten = write(fd_to, out_ptr, nread);

          if (nwritten >= 0)
          {
              nread -= nwritten;
              out_ptr += nwritten;
          } else {
            return -1;
          }

      } while (nread > 0);
  }

  close(fd_to);
  close(fd_from);
  return 0;
}

int main(int argc, char* argv[]) {

  if (argc != 3) {
    printf("Please, enter 3 argument");
    return 0;
  }

  if (strcmp(argv[1], argv[2]) == 0) {
    printf("Don't copy the file to itself");
    return 0;
  }

  if (cp(argv[1], argv[2]) == -1) {
    printf("Error occured : \n%s", strerror(errno));
  }
}
