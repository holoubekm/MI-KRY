#!/bin/bash

data_dir='data'
cat 8mhz.bit | cut -c  1 | paste -s -d '' > "${data_dir}/bit_01.bit"
cat 8mhz.bit | cut -c  2 | paste -s -d '' > "${data_dir}/bit_02.bit"
cat 8mhz.bit | cut -c  3 | paste -s -d '' > "${data_dir}/bit_03.bit"
cat 8mhz.bit | cut -c  4 | paste -s -d '' > "${data_dir}/bit_04.bit"
cat 8mhz.bit | cut -c  5 | paste -s -d '' > "${data_dir}/bit_05.bit"
cat 8mhz.bit | cut -c  6 | paste -s -d '' > "${data_dir}/bit_06.bit"
cat 8mhz.bit | cut -c  7 | paste -s -d '' > "${data_dir}/bit_07.bit"
cat 8mhz.bit | cut -c  8 | paste -s -d '' > "${data_dir}/bit_08.bit"
cat 8mhz.bit | cut -c  9 | paste -s -d '' > "${data_dir}/bit_09.bit"
cat 8mhz.bit | cut -c 10 | paste -s -d '' > "${data_dir}/bit_10.bit"
cat 8mhz.bit | cut -c 11 | paste -s -d '' > "${data_dir}/bit_11.bit"
cat 8mhz.bit | cut -c 12 | paste -s -d '' > "${data_dir}/bit_12.bit"
cat 8mhz.bit | cut -c 13 | paste -s -d '' > "${data_dir}/bit_13.bit"
cat 8mhz.bit | cut -c 14 | paste -s -d '' > "${data_dir}/bit_14.bit"
cat 8mhz.bit | cut -c 15 | paste -s -d '' > "${data_dir}/bit_15.bit"
cat 8mhz.bit | cut -c 16 | paste -s -d '' > "${data_dir}/bit_16.bit"
