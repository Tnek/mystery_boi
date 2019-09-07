#pragma once
#include "mstdlib.h"

#define strlen(buf)                                                            \
  ({                                                                           \
    size_t len = 0;                                                            \
    do {                                                                       \
      while (buf[len] != 0)                                                    \
        len++;                                                                 \
    } while (0);                                                               \
    len;                                                                       \
  })

#define print(buf)                                                             \
  do {                                                                         \
    write(stdout, buf, strlen(buf));                                           \
  } while (0)

#define fgets(str, num, stream)                                                \
  ({                                                                           \
    int len = read(stdin, str, num);                                           \
    str[len + 1] = '\0';                                                       \
    len;                                                                       \
  })
