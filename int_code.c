//****************************************************************************
//*         This is a part of the Mini-(C)ompiler Source Code. 
//*         All rights reserved. 
//****************************************************************************
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "int_code.h"
#include "defs.h"

typedef struct strQuadop
{
  char desc[11];
  int code;
}QuadOp;

QuadOp QuadOpers[] =
{
	"&",		ADDRESS,
	"ustar<*>",	USTAR,
	"uminus",	UMINUS,
	"label",	LABEL,
	"jump",		JUMP,
	"jump0",	JUMP0,
	"jump1",	JUMP1,
	"_Start_Fun",STARTFUN,
	"_End_Fun",	ENDFUN,
	"param",	PARAM,
	"call",		CALLFUN,
	"ret",		RETFUN,

	"+",		'+',
	"-",		'-',
	"*",		'*',
	"/",		'/',

	"<",		'<',
	">",		'>',

	":=",		'=',
	"*=",		M_ASSIGN,
	"/=",		D_ASSIGN,
	"+=",		A_ASSIGN,
	"-=",		S_ASSIGN,

	"&&",		AND_OPER,
	"||",		OR_OPER,

	"==",		EQ_OPER,
	"!=",		NE_OPER,

};

void InitQuads()
{
HeadQ=Quads=NULL;
TempCount=0;
Temps=create_st();
DUMMY=(entry)malloc(sizeof(struct strentry));
DUMMY->name=(char *)malloc(sizeof(char)*2);
DUMMY->IDclass=CONSTANT;
DUMMY->kind.Constant.ConstType=NULL;
strcpy(DUMMY->name,"-");
}

void gen(int op,entry arg1,entry arg2,entry arg3)
{
Quadruples NewElem;
if (Quads==NULL){
    Quads=(Quadruples)malloc(sizeof(struct strquadruples));
	Quads->op=op;
	Quads->arg1=arg1;
	Quads->arg2=arg2;
	Quads->arg3=arg3;
	Quads->next=Quads->last=NULL;
	HeadQ=Quads;
}
else{
	NewElem=(Quadruples)malloc(sizeof(struct strquadruples));
	NewElem->op=op;
	NewElem->arg1=arg1;
	NewElem->arg2=arg2;
	NewElem->arg3=arg3;
	NewElem->next=NULL;
	NewElem->last=Quads;
	Quads->next=NewElem;
	Quads=NewElem;
}
}

entry new_label()
{
  entry TempEntry=(entry)malloc(sizeof(struct strentry));
  char *TempName=(char*)malloc(7);
  sprintf(TempName,"%d", ++TempCount);
  TempEntry->name=TempName;
  TempEntry->IDclass=TEMP;
  TempEntry->kind.Temp.address=NOMADDRESS; //content only of memory
  enter(Temps,TempEntry);
  return TempEntry;  
}

entry int2entry(int num)
{
  entry retEntry=(entry)malloc(sizeof(struct strentry));
  char *strnum=(char*)malloc(6);
  sprintf(strnum,"%d", num);
  retEntry->name=strnum;
  retEntry->IDclass=CONSTANT;
  retEntry->kind.Constant.ConstValue=num;
  retEntry->kind.Constant.ConstType=NULL;
  enter(Temps,retEntry);
  return retEntry;  
}
//*****************************************************

whilestmt start_while()
{
whilestmt ws=(whilestmt)malloc(sizeof(struct strwhilestmt));
entry L=new_label();
gen(LABEL,L,DUMMY,DUMMY);
ws->top_label=L;
return ws;
}

whilestmt while_test(whilestmt *ws,express b_expr)
{
(*ws)->out_label=new_label();
if (b_expr!=NULL) //atermono loop e.g. for(i=0;;i++)
	gen(JUMP0,b_expr->place,(*ws)->out_label,DUMMY);
return *ws;
}

whilestmt gen_expr_label(whilestmt *ws)
{
entry L=new_label();
(*ws)->expr_label=L;
gen(LABEL,L,DUMMY,DUMMY);
return *ws;
}

whilestmt gen_stat_label(whilestmt *ws)
{
entry L=new_label();
(*ws)->stat_label=L;
gen(LABEL,L,DUMMY,DUMMY);
return *ws;
}

Quadruples gen_jump_stat()
{
gen(JUMP,DUMMY,DUMMY,DUMMY);
return Quads;
}


void gen_jump_top(whilestmt ws)
{
gen(JUMP,ws->top_label,DUMMY,DUMMY);
}

void gen_jump_expr(whilestmt ws)
{
gen(JUMP,ws->expr_label,DUMMY,DUMMY);
}

void backpatch_stat_label(whilestmt ws,Quadruples *Qr)
{
(*Qr)->arg1=ws->stat_label;
}

void finish_while(whilestmt *ws)
{
gen(JUMP,(*ws)->top_label,DUMMY,DUMMY);
gen(LABEL,(*ws)->out_label,DUMMY,DUMMY);
free(*ws);
}

void contbreak_while(whilestmt ws,statem st)
{
	while(st!=NULL){
		if (st->info->br!=NULL) st->info->br->arg1=ws->out_label;
		if (st->info->cont!=NULL) st->info->cont->arg1=ws->top_label;
		st=st->next;
	}

}

void conbreak_for(whilestmt ws,statem st)
{
	while(st!=NULL){
		if (st->info->br!=NULL) st->info->br->arg1=ws->out_label;
		if (st->info->cont!=NULL) st->info->cont->arg1=ws->stat_label;
		st=st->next;
	}
}

//*****************************************************
Quadruples start_fun()
{
gen(STARTFUN,DUMMY,DUMMY,DUMMY);
return Quads;
}

void backpatch_fun(Quadruples *Qr,entry proc)
{
(*Qr)->arg1=proc;
}

//*****************************************************
ifstmt start_if()
{
ifstmt is=(ifstmt)malloc(sizeof(struct strifstmt));
is->out_label=new_label();
return is;
}

ifstmt if_test(ifstmt *is,express b_expr)
{
(*is)->next_else_label=new_label();
gen(JUMP0,b_expr->place,(*is)->next_else_label,DUMMY);
return *is;
}


void gen_jump(ifstmt is)
{
gen(JUMP,is->out_label,DUMMY,DUMMY);
}

void gen_else_label(ifstmt is)
{
gen(LABEL,is->next_else_label,DUMMY,DUMMY);
}

void gen_out_label(ifstmt *is)
{
gen(LABEL,(*is)->out_label,DUMMY,DUMMY);
free(*is);
}

//*****************************************************
dostmt gen_loop_label()
{
dostmt ds=(dostmt)malloc(sizeof(struct strdostmt));
entry L=new_label();
gen(LABEL,L,DUMMY,DUMMY);
ds->top_label=L;
return ds;
}

void loop_back_test(dostmt *ds,express b_expr)
{
gen(JUMP1,b_expr->place,(*ds)->top_label,DUMMY);
}

void gen_doout_label(dostmt *ds)
{
entry L=new_label();
gen(LABEL,L,DUMMY,DUMMY);
(*ds)->out_label=L;
}

void gen_doexpr_label(dostmt *ds)
{
entry L=new_label();
gen(LABEL,L,DUMMY,DUMMY);
(*ds)->expr_label=L;
}


void contbreak_do(dostmt *ds,statem st)
{
	while(st!=NULL){
		if (st->info->br!=NULL) st->info->br->arg1=(*ds)->out_label;
		if (st->info->cont!=NULL) st->info->cont->arg1=(*ds)->expr_label;
		st=st->next;
	}
	free(*ds);
}


//*****************************************************
Quadruples start_jump()
{
gen(JUMP,DUMMY,DUMMY,DUMMY); //continue or break
return Quads;
}

jump_stat GetJumpStat(Quadruples cont,Quadruples br,char ret,express expr,char line)
{
	jump_stat newjumpstat;
	newjumpstat=(jump_stat)malloc(sizeof(struct strjump_statement));
	newjumpstat->cont=cont;
	newjumpstat->br=br;
	newjumpstat->ret=ret;
	newjumpstat->expr=expr;
	newjumpstat->line=line;
	return newjumpstat;
}

//*****************************************************
statem StartStatement(jump_stat info)
{
	statem newstat;
	newstat=(statem)malloc(sizeof(struct strexpressionlist));
	newstat->info=info;
	newstat->next=NULL;
	return newstat;
}

statem NextStatement(statem statlist,jump_stat info)
{
	statem newstat;
	newstat=StartStatement(info);
	newstat->next=statlist;
	return newstat;
}

test(statem statlist)
{

}
//*****************************************************
char *Qoper(int op)
{
int i;
int max=sizeof(QuadOpers)/sizeof(struct strQuadop);
for(i=0;i<max;i++)
   if(QuadOpers[i].code==op) return QuadOpers[i].desc;
  return "?????";
}

char *Qarg(entry arg)
{
return arg->name;
}

void SaveQuads()
{
FILE *SQ;
Quadruples HQ=HeadQ;
SQ=fopen("QUADS.OUT","w");
fprintf(SQ, "\nQuadruples:\n");
fprintf(SQ, "----------------------------------------------\n");
while (HQ!=NULL){
	fprintf(SQ,"| %-10s|%+10s|%+10s|%+10s|\n",Qoper(HQ->op),Qarg(HQ->arg1),Qarg(HQ->arg2),Qarg(HQ->arg3));
	HQ=HQ->next;
}
fprintf(SQ, "----------------------------------------------\n");
fclose(SQ);
}

void FreeQuads()
{

Quadruples HQ;
if (HeadQ!=NULL) HQ=HeadQ->next;
while (HeadQ!=NULL){
	FreeEntry(HeadQ->arg1); 
	FreeEntry(HeadQ->arg2); 
	FreeEntry(HeadQ->arg3); 
	free(HeadQ);    
	HeadQ=HQ;
	if (HQ!=NULL) HQ=HQ->next;
}
}




