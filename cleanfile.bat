@echo off

IF EXIST lex.yy.c del lex.yy.c
IF EXIST y.tab.c del y.tab.c
IF EXIST y.tab.h del y.tab.h
IF EXIST parser.exe del parser.exe