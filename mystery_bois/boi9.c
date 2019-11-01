#include "chal.h"
#include "lib/mruntime.h"
#include "lib/mstdlib.h"

int loadl(struct reg_t *reg) {
  switch (reg->r[LEN_REG]) {
  /*  */
  case 'a':
    if (reg->r[GROUP_MATCH_REG] == 0) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'b':
    if (reg->r[GROUP_MATCH_REG] == 1) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'c':
    if (reg->r[GROUP_MATCH_REG] == 2) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'd':
    if (reg->r[GROUP_MATCH_REG] == 3) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'e':
    if (reg->r[GROUP_MATCH_REG] == 4) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'f':
    if (reg->r[GROUP_MATCH_REG] == 5) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'g':
    if (reg->r[GROUP_MATCH_REG] == 6) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'h':
    if (reg->r[GROUP_MATCH_REG] == 7) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'i':
    if (reg->r[GROUP_MATCH_REG] == 8) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'j':
    if (reg->r[GROUP_MATCH_REG] == 9) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'k':
    if (reg->r[GROUP_MATCH_REG] == 10) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'l':
    if (reg->r[GROUP_MATCH_REG] == 11) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'm':
    if (reg->r[GROUP_MATCH_REG] == 12) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'n':
    if (reg->r[GROUP_MATCH_REG] == 13) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'o':
    if (reg->r[GROUP_MATCH_REG] == 14) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'p':
    if (reg->r[GROUP_MATCH_REG] == 15) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'q':
    if (reg->r[GROUP_MATCH_REG] == 16) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'r':
    if (reg->r[GROUP_MATCH_REG] == 17) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 's':
    if (reg->r[GROUP_MATCH_REG] == 18) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 't':
    if (reg->r[GROUP_MATCH_REG] == 19) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'u':
    if (reg->r[GROUP_MATCH_REG] == 20) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'v':
    if (reg->r[GROUP_MATCH_REG] == 21) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'w':
    if (reg->r[GROUP_MATCH_REG] == 22) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'x':
    if (reg->r[GROUP_MATCH_REG] == 23) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'y':
    if (reg->r[GROUP_MATCH_REG] == 24) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case 'z':
    if (reg->r[GROUP_MATCH_REG] == 25) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case '0':
    if (reg->r[GROUP_MATCH_REG] == 26) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case '1':
    if (reg->r[GROUP_MATCH_REG] == 27) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case '2':
    if (reg->r[GROUP_MATCH_REG] == 28) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case '3':
    if (reg->r[GROUP_MATCH_REG] == 29) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case '4':
    if (reg->r[GROUP_MATCH_REG] == 30) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case '5':
    if (reg->r[GROUP_MATCH_REG] == 31) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case '6':
    if (reg->r[GROUP_MATCH_REG] == 32) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case '7':
    if (reg->r[GROUP_MATCH_REG] == 33) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case '8':
    if (reg->r[GROUP_MATCH_REG] == 34) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case '9':
    if (reg->r[GROUP_MATCH_REG] == 35) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case '{':
    if (reg->r[GROUP_MATCH_REG] == 36) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case '}':
    if (reg->r[GROUP_MATCH_REG] == 37) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  case '_':
    if (reg->r[GROUP_MATCH_REG] == 38) {
      reg->r[STATE_REG] = CORRECT_CHECKER;
      RETURN_ENCODED(reg);
    }
    reg->r[STATE_REG] = FAIL_VERIFY;
    RETURN_ENCODED(reg);
    break;
  /*  */
  }
  RETURN_ENCODED(reg);
}