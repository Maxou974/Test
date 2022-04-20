#!/bin/bash
make -C ..
gcc -Wall -Werror -Wextra test_libft/test.c ../libft.a
valgrind ./a.out
