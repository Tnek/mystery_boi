
#include "chal.h"
#include "lib/mruntime.h"
#include "lib/mstdlib.h"
#include "lib/mstring.h"

int load1(struct reg_t *reg) {
  switch (reg->r[CHECKER_REG]) {
  /*  */
  case 0:
    if (reg->r[VERIFY_CHAR] == '0') {
      reg->r[GROUP_MATCH_REG] = 1;
      reg->r[STATE_REG] = VERIFY_FOUND_KEY;
      RETURN_ENCODED(reg);
    }
    reg->r[CHECKER_REG]++;
    JUMP_ENCODED(0x3732696f62);
    break;
  /*  */
  default:
    reg->r[GROUP_REG]++;
  }
  RETURN_ENCODED(reg);
}