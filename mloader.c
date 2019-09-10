#include "mloader.h"

pthread_t *jit_loop;
struct reg_t *regs;

struct reg_t *init_regs(void) {
  struct reg_t *ret = (struct reg_t *)malloc(sizeof(struct reg_t));
  memset(ret, 0, sizeof(struct reg_t));

  //  ret->flag_ptr = malloc(sizeof(enc_fleg));
  //  memcpy(ret->flag_ptr, enc_fleg, 29);

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

volatile int CHECKSUM_VALUE = 0xdc2b4047;
extern unsigned char *_start;
extern unsigned char *__etext;

void checksum_me() {
  char *start = (char *)&_start;
  char *end = (char *)&__etext;

  unsigned checksum = 0;
  unsigned word = 0;

  unsigned counter = 0;

  while (start != end) {
    if (counter == 8) {
      checksum ^= word;
      word = 0;
      counter = 0;
    }
    word = (word << 8) | ((*(volatile unsigned *)start) & 0xFF);

    counter++;
    start++;
  }

  if (checksum != CHECKSUM_VALUE) {
#ifdef DEBUG
    printf("Checksum_ptr: %x\n", checksum);
#else
    kms();
#endif
  }
}

void callfunc(int fd, struct reg_t *ptr) {
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
  int offset = 0;

  if (ptrace(PTRACE_TRACEME, 0, 1, 0) == 0) {
    offset = 1;
  }
  if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1) {
    offset *= 2;
  }

  char startfile[] = "boi0";
  startfile[3] += offset;

#ifdef DEBUG
  printf("Startfile: %s\n", startfile);
#endif

  int fd = open(startfile, O_RDONLY);

  callfunc(fd, regs);
  pthread_exit(NULL);
}

void __attribute__((constructor)) spawn_mmap(void) {
  checksum_me();
  dladdr_check("mmap", "libc.so.6");
  dladdr_check("free", "libc.so.6");
  dladdr_check("printf", "libc.so.6");
  dladdr_check("perror", "libc.so.6");
  dladdr_check("malloc", "libc.so.6");
  dladdr_check("exit", "libc.so.6");
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
