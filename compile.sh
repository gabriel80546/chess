#!/bin/bash
compile="clang -g -Weverything -O3 -I libft libft/*.c *.c"
echo $compile
$compile
