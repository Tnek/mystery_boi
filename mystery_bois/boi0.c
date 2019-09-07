#include "lib/mstdlib.h"

int load1(struct reg_t *reg) {
  long long volatile failstr = 0x000a6c696166; // fail\n

  write(stdout, &failstr, 5);
  close(reg->rf);
  return 0;
}
