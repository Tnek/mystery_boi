#include "lib/mstdlib.h"

int load1(struct reg_t *reg) {
  long long volatile failstr = 0x000a6c696166; // fail\n
  write(stdout, &failstr, 5);

  reg->r[0] = 0;
  RETURN_ENCODED(reg);
}
