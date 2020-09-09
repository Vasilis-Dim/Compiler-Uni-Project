//****************************************************************************
//*         This is a part of the Mini-(C)ompiler Source Code. 
//*         All rights reserved. 
//****************************************************************************
#ifndef   __GENER_H
#define   __GENER_H
#include "sym_tab.h"
#include "error_str.h"


//*****************************************************
//in yacc <unary_operator>
typedef struct strunary_operator
{
	char minus; //unary -
	char addr;	//unary &
	char ptr;	//unary *
}*unary_op;

unary_op GetInfoFromUnOp(char minus,char addr,char ptr);

//*****************************************************
//in yacc <primary> <unary_expr> <multiplicative_expr> <additive_expr>
//  <relational_expr> <equality_expr> <logical_and_expr> <logical_or_expr>
//  <assignment_expr>
typedef struct strexpr
{
	entry info;
	char minus; //δηλώνει αν ακολουθεί από το unary oper -
	char lvalue;//boolean:δηλώνει αν ειναι lvalue η όχι.
	entry place;
	int errorcode;
}*express;

express GetInfoFromID(char *ID);
express GetInfoFromFunc(char *funcname,symbol_table proc_st);
express GetInfoFromConst(int DecValue);
express  GetInfoFromUnExpr(unary_op unop,express primary);
//*****************************************************
//list of parameters
//in yacc <expression_list>
typedef struct strexpressionlist
{
	express expr;
	struct strexpressionlist *next;
}*expression_list;

expression_list StartExpression(express expr);
expression_list NextExpression(expression_list explist,express expr);

//*****************************************************
//list of parameters
//in yacc <parameter_list>
typedef struct strparamlist
{
	char *name;
	struct strparamlist *next;
}*param_list;

param_list StartParamIdList(char *IDENT);
param_list NextParamID(param_list ParamIdList,char *IDENT);
//*****************************************************
//in yacc <declarator2>
typedef struct strdeclar2
{
	char *name;
	char exists;     //boolean 0,1 used in extractparam for error trapping
	char proc;		 //1 if we have a procedure declaration
	param_list paridlist;
}*declar2;

declar2 GetDeclarator2(char *name,char proc,param_list paridlist);

//*****************************************************
//in yacc <declarator>
typedef struct strdeclar
{
	declar2 decl2;
	char ptrlevel;
}*declar;

declar GetDeclarator(char ptrlevel,declar2 decl2);

//*****************************************************
//list of id's
//in yacc <declarator_list>
typedef struct strdecllist
{
	declar decl;
	struct strdecllist *next;
}*decl_list;

decl_list StartIdList(declar IDENT);
decl_list NextID(decl_list IdList,declar IDENT);

//*****************************************************
//in yacc <decl_specifiers>
typedef struct strdeclspecifiers
{
	char sc_specif;
	char type_specif;
}*decl_specif;

decl_specif GetDeclSpecif(char sc_specif,char type_specif);

//*****************************************************
//in yacc <declaration>

typedef struct strdeclaration
{
	decl_specif declspecif;
	decl_list declist;
}*declaration;

declaration GetDeclaration(decl_specif dl_sp,decl_list *dl_list); 
//NULL for redefinition	(or function definition ???)

//*****************************************************
//list of id's
//in yacc <declaration_list>
typedef struct strdeclarlist
{
	declaration decl;
	struct strdeclarlist *next;
}*declaration_list;

declaration_list StartDeclarList(declaration decl);
declaration_list NextDeclar(declaration_list DeclList,declaration decl);

//*****************************************************
//in yacc <function_definition>
typedef struct strfuncdef
{
	entry entr;
	errfuncdef error;
}*funcdef;


funcdef extractproc(decl_specif d_sp,declar decl,declaration_list f_bd);
//*****************************************************

entry currproc(symbol_table table);
#endif