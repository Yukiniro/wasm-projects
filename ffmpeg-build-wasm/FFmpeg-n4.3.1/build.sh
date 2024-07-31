#!/bin/bash -x
# gcc 8 is used in this tutorial, other versions may fail
./configure --disable-x86asm
make -j