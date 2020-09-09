#ifndef   __SYM_TAB_H
#define   __SYM_TAB_H

typedef struct strentry
{
	char *name;
	char type;
	int val;
}*entry;


// symbol table
typedef struct strentlist
{
	entry id;
	struct strentlist *next;
}*entr_list;  //την χρησιμοποιεί το συγκεκριμένο symbol table 
			  //που έχουμε

typedef struct symtab
{
 entr_list st_entries;  
}*symbol_table;

symbol_table create_st(void);
void destroy_st(symbol_table table);
char enter(symbol_table table,entry entryptr);// 1 success 
entry lookup(symbol_table table,char *name);

#endif