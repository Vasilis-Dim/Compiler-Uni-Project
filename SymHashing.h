/*#include <iostream.h>*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define table_size          100

extern int line=1;
extern int end_file=1;
extern int block_num=0;
extern FILE *new_file; 

typedef struct hash_sym
	{
	struct hash_sym *prev, *next;
	char *nam;
	char *str_val;
	char *id_type;
	int  id_value;
	int  block_num;
	int  line_num;
} Hashing_table; 
 

Hashing_table *table[table_size];

int hash_funct( char str[], int hash_size);

addsym( sym, bloc_num )
register char sym[];
int bloc_num;

{   
	int hash_val = hash_funct( sym, table_size );
  	register struct hash_sym *sym_sym = table[hash_val];
	register struct hash_sym *new_sym;
	register struct hash_sym *successor;
    
	while ( sym_sym!=0 )
	{
	   	 
	if (  strcmp( sym, table[hash_val]->nam )==0 )
		{	
          
		printf(" the entry %s at line %d already exists at symbol table\n", sym,line); 	
		return -1;
		}	
	
	   	sym_sym = sym_sym->next;
	}

	
	new_sym = (struct hash_sym *)
	malloc( sizeof( struct hash_sym ) );

	
	if ( (successor = table[hash_val]) )
		{ 
		
		new_sym->next = successor;
		successor->prev = new_sym;
		}
	else
		new_sym->next = NULL;

	new_sym->prev = NULL;
	new_sym->nam = sym;
	new_sym->block_num = bloc_num;

	table[hash_val] = new_sym;
    return 0;
	}




int hash_funct( str, hash_size )
register char str[];
int hash_size;
	{
	register int hashval;
	register int i;

	hashval = 0;
	i = 0;

	while ( str[i]!='\0' )
		{
		hashval = hashval +  str[i++]*(16+i);
		/*hashval %= hash_size;*/
		}
    return (hashval %= hash_size);
	}


