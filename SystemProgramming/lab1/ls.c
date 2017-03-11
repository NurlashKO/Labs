#include <errno.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {

  DIR *dir;
  struct dirent *myfile;
  if (argc == 2)
    dir = opendir(argv[1]);
  else
    dir = opendir(".");


  if (dir == NULL) {
    printf("Can not read directory!\n %s\n", strerror(errno));
    return 0;
  }

  while((myfile = readdir(dir)) != NULL)
  {
      printf(" %s\n", myfile->d_name);
  }
  closedir(dir);
}
