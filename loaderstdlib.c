
typedef unsigned size_t;
int open(char *path, int flags) {}

int close(int fd) {
  int ret;
  asm("syscall" : "=a"(ret) :);
  return ret;
}

size_t write(int fd, void *buf, size_t nbytes) {}

size_t read(int fd, void *buf, size_t nbyte) {}
