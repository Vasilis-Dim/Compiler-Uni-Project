//****************************************************************************
//*         This is a part of the Mini-(C)ompiler Source Code. 
//*         All rights reserved. 
//****************************************************************************
#include <stdio.h>
#include <malloc.h>
#include "sym_tab.h"
#include "scope.h"
#include "defs.h"

void initstack_st(void)
{
	stack_sym_table=NULL;
}

void push_st(char block,symbol_table table)
{
	if (stack_sym_table==NULL){
		stack_st newstackel;
		newstackel=(stack_st)malloc(sizeof(struct strstack));
		newstackel->st=table;
		newstackel->block=block;
		newstackel->next=NULL;
		newstackel->offset=0; //offset=0
		stack_sym_table=Head_st=newstackel;
	}
	else {
		stack_st newstackel;
		newstackel=(stack_st)malloc(sizeof(struct strstack));
		newstackel->st=table;
		newstackel->block=block;
		if (block!=PROC_BLOCK)
			newstackel->offset=stack_sym_table->offset; //offset
		else newstackel->offset=0; 
		newstackel->next=stack_sym_table;
		stack_sym_table=Head_st=newstackel;
	}
}

symbol_table pop_st(void)
{
	stack_st stackel;
	if ((stack_sym_table!=NULL)&&(stack_sym_table->next!=NULL))//kratame tis globals
	{
		stackel=stack_sym_table;
		stack_sym_table=stack_sym_table->next;
		return stackel->st;
	}
	else return NULL;
}

symbol_table current_scope(void)
{
	if (stack_sym_table!=NULL) return stack_sym_table->st;
	else return NULL;
}

void mergeblocks(void)
{
	if ((stack_sym_table!=NULL)&&(stack_sym_table->next!=NULL))
		if (stack_sym_table->next->block==PROC_BLOCK){
			stack_sym_table=stack_sym_table->next;
			stack_sym_table->block=PURE_BLOCK;
			stack_sym_table->offset=0; //offset=0;
		}
}

char getblockinfo(void)
{
if (stack_sym_table!=NULL) return stack_sym_table->block;
	else return PURE_BLOCK;
}

entry find_ID(char *name)
{
	stack_st tmpptr=stack_sym_table;
	entry obt_entry=NULL;
	while ((stack_sym_table!=NULL)&&((obt_entry=lookup(current_scope(),name))==NULL))
			stack_sym_table=stack_sym_table->next;
	stack_sym_table=tmpptr;
	return obt_entry;
}

void freestack_st()
{

stack_st SST;
if (Head_st!=NULL) SST=Head_st->next;
while (Head_st!=NULL){
	free(Head_st->st);
	free(Head_st);    
	Head_st=SST;
	if (SST!=NULL) SST=SST->next;
}
}
