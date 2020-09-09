@echo off
title Makefile

cls
bison -dy gram.y
flex minimal++.l
gcc -o parser.exe lex.yy.c y.tab.c sym_tab.c gener.c scope.c
pause

