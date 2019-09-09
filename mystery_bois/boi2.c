#include "chal.h"
#include "lib/mruntime.h"
#include "lib/mstdlib.h"
#include "lib/mstring.h"

// Dispatch table for fetching input
int load1(struct reg_t *reg) {
  switch (reg->r[STATE_REG]) {
  case READ_INPUT:
    reg->r[A1_REG] = READ_LEN;
    CALL_ENCODED(reg, BOI4_BIN);
    break;
  case VERIFY_LENGTH:
    CALL_ENCODED(reg, BOI5_BIN);
    break;
  case VERIFY_VALUE:
    JUMP_ENCODED(BOI3_BIN);
    break;
  case FAIL_RESET:
    CALL_ENCODED(reg, BOI0_BIN);
    break;
  };
  RETURN_ENCODED(reg);
}
