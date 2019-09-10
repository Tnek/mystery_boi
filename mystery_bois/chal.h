#pragma once
#include "lib/mruntime.h"
#include "lib/mstdlib.h"

#define BOIC_BIN 0x0063696f62
#define BOI7_BIN 0x0037696f62
#define BOI6_BIN 0x0036696f62
#define BOI5_BIN 0x0035696f62
#define BOI4_BIN 0x0034696f62
#define BOI3_BIN 0x0033696f62
#define BOI2_BIN 0x0032696f62
#define BOI1_BIN 0x0031696f62
#define BOI0_BIN 0x0030696f62

enum state {
  READ_INPUT,
  VERIFY_LENGTH,
  VERIFY_VALUE,
  FAIL_RESET,
  VERIFY_POP_CHAR,
  VERIFY_CHAR,
  PARSE_FINISH,
  FAIL_VERIFY
};

#define A1_REG 1

#define FAIL_REG 4
#define LEN_REG 5
#define POP_REG 6
#define STATE_REG 7

#define FLAG_LEN 3
#define READ_LEN 32

#define FAIL(reg)                                                              \
  { CALL_ENCODED(reg, BOI0_BIN) }

#define YOU_WIN(reg)                                                           \
  { CALL_ENCODED(reg, BOI1_BIN) }
