#!/bin/bash
curl -o helper.so https://github.com/benjamesian/holbertonschool-low_level_programming/blob/master/0x18-dynamic_libraries/0x17.c/helper.so
export LD_PRELOAD=./helper.so
