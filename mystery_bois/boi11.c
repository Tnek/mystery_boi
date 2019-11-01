
#include "chal.h"
#include "lib/mruntime.h"
#include "lib/mstdlib.h"
#include "lib/mstring.h"

int load1(struct reg_t *reg) {
  /*  */
  if (reg->r[CHECKER_REG] == 0) {
    if (reg->r[POP_REG] == 'n') {
      reg->r[GROUP_MATCH_REG] = 33;
      reg->r[STATE_REG] = VERIFY_FOUND_KEY;
      RETURN_ENCODED(reg);
    }
    reg->r[CHECKER_REG]++;
    JUMP_ENCODED(0x3131696f62);
  }
  /*  */
  if (reg->r[CHECKER_REG] == 1) {
    if (reg->r[POP_REG] == '4') {
      reg->r[GROUP_MATCH_REG] = 32;
      reg->r[STATE_REG] = VERIFY_FOUND_KEY;
      RETURN_ENCODED(reg);
    }
    reg->r[CHECKER_REG]++;
    JUMP_ENCODED(0x3131696f62);
  }
  /*  */
  if (reg->r[CHECKER_REG] == 2) {
    if (reg->r[POP_REG] == 'z') {
      reg->r[GROUP_MATCH_REG] = 31;
      reg->r[STATE_REG] = VERIFY_FOUND_KEY;
      RETURN_ENCODED(reg);
    }
    reg->r[CHECKER_REG]++;
    JUMP_ENCODED(0x3131696f62);
  }
  /*  */
  if (reg->r[CHECKER_REG] == 3) {
    if (reg->r[POP_REG] == 'x') {
      reg->r[GROUP_MATCH_REG] = 30;
      reg->r[STATE_REG] = VERIFY_FOUND_KEY;
      RETURN_ENCODED(reg);
    }
    reg->r[CHECKER_REG]++;
    JUMP_ENCODED(0x3131696f62);
  }
  /*  */
  if (reg->r[CHECKER_REG] == 4) {
    if (reg->r[POP_REG] == 'g') {
      reg->r[GROUP_MATCH_REG] = 29;
      reg->r[STATE_REG] = VERIFY_FOUND_KEY;
      RETURN_ENCODED(reg);
    }
    reg->r[CHECKER_REG]++;
    JUMP_ENCODED(0x3131696f62);
  }
  /*  */
  if (reg->r[CHECKER_REG] == 5) {
    if (reg->r[POP_REG] == 'p') {
      reg->r[GROUP_MATCH_REG] = 28;
      reg->r[STATE_REG] = VERIFY_FOUND_KEY;
      RETURN_ENCODED(reg);
    }
    reg->r[CHECKER_REG]++;
    JUMP_ENCODED(0x3131696f62);
  }
  /*  */

  reg->r[CHECKER_REG] = 0;
  reg->r[GROUP_REG]++;
  RETURN_ENCODED(reg);
}