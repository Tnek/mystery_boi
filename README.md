# Mystery Boi
## Description
400 point Reverse Engineering Challenge in CSAW CTF 2019 Finals.

"who am I? none of your business

`nc {{.Netloc}} {{.DescPort}}`

## Flag
flag{jk_there_was_no_mystery}

## Notes
Competitors were only given a link to a service and a launcher file.
This file will pull their payload and `LD_PRELOAD` it to a mystery binary.

This mystery binary had a few antidebug checks, preventing them from LD\_PRELOADing to a few standard functions. The intended function to overload was `__libc_start_main`, which would allow them to them extract the files of the mystery binary.

There are 26 files in the mystery binary, with `mystery_boi` being a loader that mapped a new executable page and opened one of the other files. These files make up a large state machine opens and executes other binaries.
