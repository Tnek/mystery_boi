#include "mloader.h"
#define JIT_START_FILE "boi2bin"

pthread_t *jit_loop;
struct reg_t *regs;

int enc_fleg[] = {-75, -117, 24, 6,  -54, 33, 114, 78, 99, 87,
                  60,  -63,  60, 78, 54,  24, 18,  78, 45, -90,
                  78,  -36,  0,  18, 99,  60, -63, 0,  108};

struct reg_t *init_regs(void) {
  struct reg_t *ret = (struct reg_t *)malloc(sizeof(struct reg_t));
  memset(ret, 0, sizeof(struct reg_t));

  ret->flag_ptr = malloc(sizeof(enc_fleg));
  memcpy(ret->flag_ptr, enc_fleg, 29);

  ret->cs = mmap(0, PAGE_SIZE, PROT_READ | PROT_WRITE | PROT_EXEC,
                 MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  if (ret->cs == (void *)-1) {
    perror("mmap failed");
    exit(1);
  }

  ret->sp = malloc(sizeof(char) * STACK_SIZE);
  ret->rfs = malloc(CALLSTACK_DEPTH * sizeof(int));
  memset(ret->rfs, -1, CALLSTACK_DEPTH * sizeof(int));
  ret->rfs++;
  return ret;
}

void callfunc(char *startfile, struct reg_t *ptr) {
  int fd = open(startfile, O_RDONLY);
  ptr->rf = fd;

  while (fd != -1) {
    lseek(fd, 0, SEEK_SET);
    if (read(fd, ptr->cs, PAGE_SIZE - 1) != 0) {
      jit_func_t func = ptr->cs; // The function should close it's own fd
#ifdef DEBUG
      printf("func %d ret %d\n", fd, *ptr->rfs);
#endif
      fd = func(ptr);
    }
  }
  printf("Test exit %d\n", fd);
}

void *jit_thread_func(void *vargp) {
  callfunc(JIT_START_FILE, regs);
  pthread_exit(NULL);
}

void __attribute__((constructor)) spawn_mmap(void) {
  dladdr_check("mmap", "libc.so.6");
  dladdr_check("free", "libc.so.6");
  dladdr_check("printf", "libc.so.6");
  dladdr_check("perror", "libc.so.6");
  dladdr_check("malloc", "libc.so.6");
  dladdr_check("calloc", "libc.so.6");
  dladdr_check("memset", "libc.so.6");
  dladdr_check("pthread_create", "libpthread.so.0");
  dladdr_check("pthread_exit", "libpthread.so.0");

  jit_loop = malloc(sizeof(pthread_t));
  regs = init_regs();

  pthread_create(jit_loop, NULL, jit_thread_func, NULL);
  pthread_join(*jit_loop, NULL);
}

int main(int argc, char *argv[]) {
  printf("Good bye\n");
  return 0;
}
