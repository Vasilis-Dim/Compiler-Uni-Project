//****************************************************************************
//*         This is a part of the Mini-(C)ompiler Source Code. 
//*         All rights reserved. 
//****************************************************************************
#ifndef   __SCOPE_H
#define   __SCOPE_H
#include "sym_tab.h"

typedef struct strstack
{
	symbol_table st;
	char block;         //kind of block ,Proc or pure
	int offset;			//offset
	struct strstack *next;
}*stack_st;

stack_st stack_sym_table,Head_st;

void initstack_st(void);
void push_st(char block,symbol_table table);
symbol_table pop_st(void);
symbol_table current_scope(void);
void mergeblocks(void);
//βάζει σ' ένα block τις formal παραμετρους μιας συνάρτησης
//με τις δηλώσεις των μεταβλητών που ανήκουν στο αμέσως επόμενο
//block
entry find_ID(char *name);
//ψαχνει να βρεί το ID(name) πρώτα στο τρέχων μπλοκ. Αν δεν το βρεί
//συνεχίζει στο αμέσως προηγούμενο στο οποίο ανήκει κ.ο.κ 
//επιστρέφει null αν δεν έχει δηλωθεί(δεν το έχει βρεί).
void freestack_st();

#endif