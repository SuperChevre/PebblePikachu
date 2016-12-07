#!/bin/bash

cat generate_c_header.inc.c

/usr/bin/python3 generate_c.py $1

cat generate_c_footer.inc.c
