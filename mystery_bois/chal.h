#pragma once
#include "lib/mruntime.h"
#include "lib/mstdlib.h"

#define BOIC_BIN 0x006e696263696f62
#define BOI6_BIN 0x006e696236696f62
#define BOI5_BIN 0x006e696235696f62
#define BOI4_BIN 0x006e696234696f62
#define BOI3_BIN 0x006e696233696f62
#define BOI2_BIN 0x006e696232696f62
#define BOI1_BIN 0x006e696231696f62
#define BOI0_BIN 0x006e696230696f62

enum state { READ_INPUT, VERIFY_LENGTH, VERIFY_VALUE, FAIL_RESET };

#define STATE_REG 7

#define FLAG_LEN 2
#define READ_LEN 32

#define FAIL(reg)                                                              \
  { CALL_ENCODED(reg, BOI0_BIN) }

#define YOU_WIN(reg)                                                           \
  { CALL_ENCODED(reg, BOI1_BIN) }
