#include "chal.h"
#include "lib/mruntime.h"
#include "lib/mstdlib.h"
#include "lib/mstring.h"

// Dispatch table
int load1(struct reg_t *reg) {
  // read input into reg->sp
  if (reg->r[0] == 0) {
    reg->r[1] = 32;
    CALL_ENCODED(reg, BOI4_BIN);
  }

  // check reg->sp input
  if (reg->r[0] == 1) {
    CALL_ENCODED(reg, BOI5_BIN);
  }

  if (reg->r[0] == 2) {
    CALL_ENCODED(reg, BOI3_BIN);
  }
  JUMP_ENCODED(BOI1_BIN);

  RETURN_ENCODED(reg);
}
