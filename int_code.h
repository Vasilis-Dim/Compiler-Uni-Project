//****************************************************************************
//*         This is a part of the Mini-(C)ompiler Source Code. 
//*         All rights reserved. 
//****************************************************************************
#ifndef   __INTCODE_H
#define   __INTCODE_H
#include "sym_tab.h"
#include "gener.h"

#define ADDRESS		299
#define USTAR		300
#define UMINUS		301
#define LABEL		302
#define JUMP		303
#define JUMP0		304
#define JUMP1		305
#define STARTFUN	306
#define ENDFUN		307
#define PARAM		308
#define CALLFUN		309
#define RETFUN		310

#define M_ASSIGN	320
#define D_ASSIGN	321
#define A_ASSIGN	322
#define S_ASSIGN	323

#define AND_OPER	330
#define OR_OPER		331

#define EQ_OPER		340
#define NE_OPER		341



//*****************************************************
typedef struct strquadruples
{	
	int op;
	entry arg1,arg2,arg3;
	struct strquadruples *next,*last;
}*Quadruples; 
//*****************************************************
//in yacc <jump_statement>
typedef struct strjump_statement
{
	Quadruples cont;	//continue
	Quadruples br;		//break
	char ret;			//return
	express expr;
	char line;
}*jump_stat;


Quadruples start_jump();
jump_stat GetJumpStat(Quadruples cont,Quadruples br,char ret,express expr,char line);
//*****************************************************
//in yacc <statement> <statement_list> <compound_statement>
typedef struct strstatement
{
	jump_stat info;
	struct strstatement *next;
}*statem;

statem StartStatement(jump_stat info);
statem NextStatement(statem statlist,jump_stat info);
test(statem statlist);

//*****************************************************
//in yacc <while_stmt>
typedef struct strwhilestmt
{
	entry top_label,out_label,expr_label,stat_label;
}*whilestmt;

whilestmt start_while();
whilestmt while_test(whilestmt *ws,express b_expr);

whilestmt gen_expr_label(whilestmt *ws);
whilestmt gen_stat_label(whilestmt *ws);//

Quadruples gen_jump_stat();//
void gen_jump_top(whilestmt ws);
void gen_jump_expr(whilestmt ws);

void backpatch_stat_label(whilestmt ws,Quadruples *Qr);
void finish_while(whilestmt *ws);

//*****************************************************
// break - continue 
void contbreak_while(whilestmt ws,statem st); //while
void conbreak_for(whilestmt ws,statem st); //for
//*****************************************************
//in yacc <function_definition>
Quadruples start_fun();
void backpatch_fun(Quadruples *Qr,entry proc);
//*****************************************************
//in yacc <if_stmt>
typedef struct strifstmt
{
	entry out_label,next_else_label;
}*ifstmt;

ifstmt start_if();
ifstmt if_test(ifstmt *is,express b_expr);
void gen_jump(ifstmt is);
void gen_else_label(ifstmt is);
void gen_out_label(ifstmt *is);

//*****************************************************
//in yacc <do_stmt>
typedef struct strdostmt
{
	entry top_label,expr_label,out_label;
}*dostmt;

dostmt gen_loop_label();
void loop_back_test(dostmt *ds,express b_expr);
void gen_doout_label(dostmt *ds);
void gen_doexpr_label(dostmt *ds);
void contbreak_do(dostmt *ds,statem st);

//*****************************************************

int TempCount;
symbol_table Temps;//ekei kratountai ta onomata twn temps
Quadruples HeadQ,Quads;
entry DUMMY;

void InitQuads();
void gen(int op,entry arg1,entry arg2,entry arg3);
entry new_label();
entry int2entry(int num);
void SaveQuads();
void FreeQuads();

#endif


