#include "chal.h"
#include "lib/mruntime.h"
#include "lib/mstdlib.h"
#include "lib/mstring.h"

int loadl(int fd, struct reg_t *reg) {
  /*
if (reg->r[0] == 2) {
  //  reg->r[0] = 3;
  //    reg->r[7] = ((char *)reg->sp)[0];
  //    reg->r[6] = 0;
}
*/

  JUMP_ENCODED(BOI1_BIN);
  RETURN_ENCODED(reg);
}
