//****************************************************************************
//*         This is a part of the Mini-(C)ompiler Source Code. 
//*         All rights reserved. 
//****************************************************************************
#ifndef   __ERROR_STR_H
#define   __ERROR_STR_H


//*****************************************************
//struct error  for <function_definition>
typedef struct strerrfuncdef
{
	char *formal_pname;
	char code;
}*errfuncdef;

//*****************************************************
//struct error  for CheckContinueBreak in check.h

typedef struct strerrconbr
{
	int line;		//line number
	char *mess;
}*errconbr;

//*****************************************************




#endif