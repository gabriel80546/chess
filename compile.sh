#!/bin/bash
compile="clang -Weverything -O3 -I libft libft/*.c *.c"
echo $compile
$compile
