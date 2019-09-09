#include "chal.h"
#include "lib/mruntime.h"
#include "lib/mstdlib.h"

int loadl(struct reg_t *reg) {
  char *sp = (char *)reg->sp;
  char c = sp[0];
  reg->sp++;
  reg->r[POP_REG] = c;
  reg->r[LEN_REG]++;
  reg->r[STATE_REG] = VERIFY_CHAR;

  if (c == 0) {
    reg->r[STATE_REG] = PARSE_FINISH;
  }
  RETURN_ENCODED(reg);
}
