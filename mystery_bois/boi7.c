#include "chal.h"
#include "lib/mruntime.h"
#include "lib/mstdlib.h"

int loadl(struct reg_t *reg) {
  reg->r[STATE_REG] = VERIFY_POP_CHAR;
  switch (reg->r[LEN_REG]) {
  case 1:
    break;
  case 2:
    break;
  default:
    break;
  };
  RETURN_ENCODED(reg);
}
