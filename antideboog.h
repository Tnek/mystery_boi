#pragma once

#include <dlfcn.h>
#include <stdlib.h>
#include <unistd.h>

#define kms()                                                                  \
  do {                                                                         \
    write(1, "Nice try but my LD gongfu is stronger than your LD gongfu\n",    \
          58);                                                                 \
    exit(1);                                                                   \
  } while (0)

#define dladdr_check(symbol, lib)                                              \
  do {                                                                         \
    void *dls_handle;                                                          \
    if (!(dls_handle = dlopen(lib, RTLD_LAZY))) {                              \
      kms();                                                                   \
    }                                                                          \
    void *real_symbol = dlsym(dls_handle, symbol);                             \
    void *next_sym = dlsym(RTLD_NEXT, symbol);                                 \
    if (real_symbol != next_sym) {                                             \
      kms();                                                                   \
    }                                                                          \
  } while (0)
