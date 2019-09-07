#include "chal.h"
#include "lib/mruntime.h"
#include "lib/mstdlib.h"
#include "lib/mstring.h"

// Takes input onto reg->sp and verifies that it's the right length
// r[0] has the length to assert with
int load1(struct reg_t *reg) {
  if (reg->r[0] == 0) {
    reg->r[1] = 32;
    CALL_ENCODED(reg, BOI4_BIN);
  }

  char *out = "asdf";
  write(stdout, out, 4);

  if (strlen(((char *)reg->sp)) < 30) {
    FAIL(reg);
  }

  RETURN_ENCODED(reg);
}
