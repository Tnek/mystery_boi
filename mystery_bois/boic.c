#include "chal.h"
#include "lib/mstdlib.h"

int loadl(int volatile fd, struct reg_t *reg) {

  if (reg->r[0] <= 0 || reg->r[1] <= 3) {
    close(fd);
    return reg->rf;
  }

  reg->r[reg->r[1]] = reg->r[0] % 3;
  reg->r[0] = reg->r[0] / 3;
  reg->r[1]--;

  return fd;
}
