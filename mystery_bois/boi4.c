#include "chal.h"
#include "lib/mruntime.h"
#include "lib/mstdlib.h"
#include "lib/mstring.h"

// Takes input onto reg->sp and verifies that it's the right length
// r[1] -> length to read
// r[0] -> length read
int load1(struct reg_t *reg) {
  long long volatile hallo = 0x203e0a6f64646168; // "haddo\n> "
  write(stdout, &hallo, 8);

  char *to_write = (char *)reg->sp;
  int len = fgets(to_write, reg->r[1], stdin);
  write(stdout, reg->sp, len);
  reg->r[0] = 1;

  RETURN_ENCODED(reg);
}
