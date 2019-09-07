#pragma once

#define PAGE_SIZE 4096
#define CALLSTACK_DEPTH 1024
#define STACK_SIZE 1024 // 512 bytes

#ifdef _MSTDLIB
#include "mstdint.h"
#include "mstdlib.h"
#endif

struct reg_t {
  void *cs; // ptr to code of mmaped page
  void *sp; // ptr to fake data stack

  int *rfs; // fd return callstack

  int volatile rf; // fd # of current module. effectively IP
  int *volatile flag_ptr;

  long long volatile r[8]; // 8 GPRs
};

typedef int (*jit_func_t)(struct reg_t *);

#define CALL_ENCODED(reg, encoded_fname)                                       \
  reg->rfs++;                                                                  \
  *(reg->rfs) = reg->rf;                                                       \
  long long volatile next_file = encoded_fname;                                \
  reg->rf = open(&next_file, O_RDONLY, NULL);                                  \
  return reg->rf;

#define RETURN_ENCODED(reg)                                                    \
  close(reg->rf);                                                              \
  reg->rf = *(reg->rfs);                                                       \
  reg->rfs--;                                                                  \
  return reg->rf;
