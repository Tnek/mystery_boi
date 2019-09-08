#!/bin/bash
make clean
make
(cd distribute; ./mloader)
