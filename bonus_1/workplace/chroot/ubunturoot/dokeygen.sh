#!/bin/bash
MAGICPID=1
LD_PRELOAD=/getpid.so

export MAGICPID
export LD_PRELOAD

# /usr/bin/ssh-keygen -N "" $@
# ./getpid

echo "$$"
