#include "chal.h"
#include "lib/mstdlib.h"
#include "lib/mstring.h"

int loadl(int fd, struct reg_t *reg) {
  char volatile inp = *((char *)reg->sp);

  if (inp == 0) {
    YOU_WIN(reg);
  }

  if (reg->rf != fd) {
    reg->rf = fd;
    reg->r[0] = inp;
    reg->r[1] = 8;
    CALL_ENCODED(reg, BOIC_BIN);

  } /*else {
      reg->rf = 0;

      int volatile p = 1;
      int volatile s = 0;

      for (int i = 3; i < 8 + 3; i++) {
          p *= 3;
          s += p * (reg->r[i] - 1);
      }

      if (s == *(reg->flag_ptr) ) {
          (reg->flag_ptr)++;
          reg->sp = ((char *) reg->sp) + 1;
          return fd;
      } else {
          FAIL();
      }
  }
  */
  FAIL(reg);
}
