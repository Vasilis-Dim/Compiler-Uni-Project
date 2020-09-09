//****************************************************************************
//*         This is a part of the Mini-(C)ompiler Source Code. 
//*         All rights reserved. 
//****************************************************************************
#ifndef   __DEFS_H
#define   __DEFS_H

#define CHAR_SIZE 1 //offsets
#define INT_SIZE  1
#define PTR_SIZE  1

#define GLOBAL		1
#define NOGLOBAL	0

#define MADDRESS	1
#define NOMADDRESS	0


#define CHAR_TYPE 0
#define INT_TYPE  1
#define VOID	  2 
#define CONST	3

#define AUTO_SC   0
#define EXTERN_SC 1
#define NO_SC     2

#define PURE_BLOCK  0
#define PROC_BLOCK  1

#define NOPROC_DECLAR  0 
#define PROC_DECLAR    1 //για δηλώσεις συναρτήσεων

#define ISLVALUE	1 //lvalue
#define ISNOTLVALUE	0

#define CHECK_CONTIBREAK	1
#define NOCHECK_CONTIBREAK	0
 

#endif