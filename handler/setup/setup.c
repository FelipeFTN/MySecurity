#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "setup.h"

int copy(char *src_path, char *dst_path);
int check_os();

// Install MySecurity on local machine
int auto_installer() {
  int err;
  char *path;

  if (check_os() != 1) { return 0; }

  err = sprintf(
      path, "%s\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup",
      getenv("APPDATA"));
  if (err < 0) {
    return err;
  }

  err = copy("MySecurty.exe", path);
  if (err < 0) {
    return err;
  }

  return 0;
}

int copy(char *src_path, char *dst_path) {
  int src_fd, dst_fd, n, err;
  unsigned char buffer[4096];

  src_fd = open(src_path, O_RDONLY);
  dst_fd = open(dst_path, O_CREAT | O_WRONLY);

  while (1) {
    err = read(src_fd, buffer, 4096);
    if (err == -1) {
      printf("Error reading file.\n");
      return -1;
    }
    n = err;

    if (n == 0)
      break;

    err = write(dst_fd, buffer, n);
    if (err == -1) {
      printf("Error writing to file.\n");
      return -1;
    }
  }

  close(src_fd);
  close(dst_fd);
  return 0;
}

int check_os() {
#ifdef _WIN32
  return 1;
#else
  return 0;
#endif
}
