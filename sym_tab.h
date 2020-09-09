//****************************************************************************
//*         This is a part of the Mini-(C)ompiler Source Code. 
//*         All rights reserved. 
//****************************************************************************
#ifndef   __SYM_TAB_H
#define   __SYM_TAB_H

typedef struct strdescriptor
{
	char sc_specif;   //auto, extern
	char type_specif; //int, char
	char ptrLevel;    //0 if id isn't pointer
}*TypeDescriptor;

enum id_class {TEMP,CONSTANT,VARIABLE,VALUEPARAM,VARPARAM,PROC}; 

typedef struct strentry
{
	char *name;
	struct strentry *previous;
	enum id_class IDclass;
	union 
	{
		struct {
			int ConstValue;
			TypeDescriptor ConstType;
		}Constant;

		struct {
		char address;
		}Temp;

		struct {
			TypeDescriptor typeDesc;
			int offset;
			char global;
		}Variable,ValueParam,VarParam;

		struct {
			struct strentry *LastParam;
			TypeDescriptor ReturnType;
		}Proc;
	}kind;
}*entry;

// symbol table
typedef struct strentlist
{
	entry id;
	struct strentlist *next;
}*entr_list;    //την χρησιμοποιεί το συγκεκριμένο symbol table 
			  //που έχουμε

typedef struct symtab
{
 entr_list st_entries;  
}*symbol_table;

symbol_table create_st(void);
void destroy_st(symbol_table table);
char enter(symbol_table table,entry entryptr);// 1 success 
entry lookup(symbol_table table,char *name);
void FreeEntry(entry entr);

#endif