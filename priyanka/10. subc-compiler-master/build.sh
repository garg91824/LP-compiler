#!/bin/bash
lex subc-compiler.l
yacc subc-compiler.y
gcc y.tab.c -ll -ly
sudo ./a.out test
