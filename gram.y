%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "sym_tab.h"
#include "gener.h"
#include "err_code.h"


extern void printerr(errconbr errmess);

extern void savefunc(funcdef func);
extern char *GetYYText(void);
extern char *yytext;
extern int line;

extern int yyylex();
extern int yyparse();
extern int yylineno;
extern void yyerror(char*);

symbol_table proc_st;

#define YYERROR_VERBOSE

#define YYPRINT(file, type, value)   yyprint (file, type, &value);


#define SYMTABSIZE 		100
#define IDLENGTH		15 
#define NOTHING			-1
#define INDENTOFFSET	2


#ifdef DEBUG
char *NodeName[] =
{
"N_PROGRAM", "N_IDENTIFIER", "N_BLOCK", "N_DECLARATIONS", "N_DECLOOP", "N_VARLIST", "N_VARLOOP",
"N_SUBPROGRAMS", "N_SUBLOOP", "N_FUNC", "N_FUNCBODY", "N_FORMALPARS", "N_FORMALPARLIST", "N_FORMALPARLIST_LOOP", "N_FORMALPARITEM", "N_BRACK_OR_STAT", 
"N_BRACKETS_SEQ", "N_SEQUENCE", "N_SEQLOOP", "N_STATEMENT", "N_ASSIGNMENT_STAT", "N_IF_STAT", "N_ELSEPART", "N_WHILE_STAT",  "N_DOUBLE_WHILE_STAT",
"N_LOOP_STAT", "N_FORCASE_STAT", "N_INCASE_STAT", "N_WHEN_LOOP", "N_WHEN_STAT", "N_EXIT_STAT", "N_RETURN_STAT", "N_PRINT_STAT", "N_INPUT_STAT", "N_CALL_STAT",
"N_ACTUALPARS", "N_ACTUALPARLIST", "N_ACTLOOP", "N_ACTUALPARITEM", "N_CONDITION", "N_BOOLTLOOP", "N_BOOLTERM", "N_BOOLFLOOP", "N_BOOLFACTOR", "N_EXPRESSION",
"N_ADDOPERTERMLOOP", "N_TERM", "N_MULOPERTERMLOOP", "N_FACTOR", "N_IDTAIL", "N_RELATIONAL_OPER", "N_ADD_OPER", "N_MUL_OPER", "N_OPTIONAL_SIGN", "N_PRIMARY"
};
#endif


enum ParseTreeNodeType { N_PROGRAM, N_IDENTIFIER, N_BLOCK, N_DECLARATIONS, N_DECLOOP, N_VARLIST, N_VARLOOP,
N_SUBPROGRAMS, N_SUBLOOP, N_FUNC, N_FUNCBODY, N_FORMALPARS, N_FORMALPARLIST, N_FORMALPARLIST_LOOP, N_FORMALPARITEM, N_BRACK_OR_STAT, 
N_BRACKETS_SEQ, N_SEQUENCE, N_SEQLOOP, N_STATEMENT, N_ASSIGNMENT_STAT, N_IF_STAT, N_ELSEPART, N_WHILE_STAT,  N_DOUBLE_WHILE_STAT,
N_LOOP_STAT, N_FORCASE_STAT, N_INCASE_STAT, N_WHEN_LOOP, N_WHEN_STAT, N_EXIT_STAT, N_RETURN_STAT, N_PRINT_STAT, N_INPUT_STAT, N_CALL_STAT,
N_ACTUALPARS, N_ACTUALPARLIST, N_ACTLOOP, N_ACTUALPARITEM, N_CONDITION, N_BOOLTLOOP, N_BOOLTERM, N_BOOLFLOOP, N_BOOLFACTOR, N_EXPRESSION,
N_ADDOPERTERMLOOP, N_TERM, N_MULOPERTERMLOOP, N_FACTOR, N_IDTAIL, N_RELATIONAL_OPER, N_ADD_OPER, N_MUL_OPER, N_OPTIONAL_SIGN,N_PRIMARY
};

	
struct treeNode {
	union {
    int item;
    char *stem;
   	};

	int nodeIdentifier;
	struct treeNode *first;
	struct treeNode *second;
	struct treeNode *third;
};	
	
void PrintTree(struct treeNode*);

	
	
struct symTabNode {
	int id;
	int blockNumber;
	char identifier[IDLENGTH];
} ;



typedef struct treeNode TREE_NODE;
typedef TREE_NODE *TERNARY_TREE;


typedef struct  symTabNode  SYMTABNODE;
typedef SYMTABNODE    *SYMTABNODEPTR;


SYMTABNODEPTR symTab[SYMTABSIZE];
int currentSymTabSize = 0;

TERNARY_TREE int_node(int, int, TERNARY_TREE, TERNARY_TREE, TERNARY_TREE);
TERNARY_TREE string_node(char *, int, TERNARY_TREE, TERNARY_TREE, TERNARY_TREE);


#ifdef DEBUG
void PrintTree(TERNARY_TREE);
#endif


%}


%union {
	char *name;
	char *cVal;
	int iVal;
	struct treeNode *tVal;
	express expr;
    funcdef funcentr;
	int op;
}


%token CALL
%token ASSIGN
%token NOT AND OR 
%token STRING_LITERAL
%token PLUS MINUS STAR DIV
%token IN INOUT INPUT PRINT
%token SEMICOLON COMMA COLON
%token PROGRAM DECLARE DEFAULT FUNCTION PROCEDURE
%token L_THAN G_THAN EQUAL L_EQ_THAN G_EQ_THAN NEQUAL
%token LPAREN RPAREN LSQUARE_BRACK RSQUARE_BRACK LBRACK RBRACK
%token ELSE IF RETURN WHILE DOUBLEWHILE LOOP FORCASE INCASE WHEN EXIT

%token<iVal> DEC_CONST

%token<cVal> IDENTIFIER

%type<tVal> program identifier block declarations decloop varlist varloop	
			subprograms subloop func funcbody formalpars formalparlist 
			formalparlist_loop formalparitem brack_or_stat brackets_seq
			sequence seqloop statement assignment_stat if_stat elsepart	
			while_stat double_while_stat loop_stat forcase_stat incase_stat	
			when_loop when_stat exit_stat return_stat print_stat input_stat 
			call_stat actualpars actualparlist actloop actualparitem condition 
			booltloop boolfloop boolfactor expression addopertermloop term
			mulopertermloop factor idtail relational_oper add_oper mul_oper
			optional_sign primary boolterm


%start program


%%



program
		: PROGRAM identifier block
		{
			TERNARY_TREE ParseTree;
		    ParseTree = int_node($2,N_PROGRAM,$2,$3,NULL);
		}
		;
		
identifier
		: IDENTIFIER 
			{
				$$=GetYYText();
				$$ = string_node($1,N_IDENTIFIER,NULL,NULL,NULL);
			}
			;
	
primary
        : identifier	
			{
				$$=GetInfoFromID($1); 
			 		if ($$->errorcode==ID_NOTFOUND){
					char *errmess=(char *)malloc(sizeof(char)*100);
					sprintf(errmess,"Identifier '%s' not found",$$->place->name);
					yyerror(errmess);
			}	
			}	
        | DEC_CONST
			{
				$$=GetInfoFromConst(atoi(yytext));
				$$ = int_node($1,N_PRIMARY,NULL,NULL,NULL);

			}
			;

block
        : begin_bl declarations subprograms sequence end_bl
		{
			$$ = int_node(NOTHING,N_BLOCK,$2,$3,$4);
		}
		;

begin_bl
		:	LBRACK 
			
		;
		
end_bl
		:	  
			RBRACK
			
		;

declarations
        : DECLARE varlist SEMICOLON decloop	
		{
			$$ = int_node(NOTHING,N_DECLARATIONS,$2,$4,NULL);	
		}
		;

decloop
		:declarations decloop
		{
			$$ = int_node(NOTHING,N_DECLOOP,$1,$2,NULL);
		}
		| 
		{
			$$ = int_node(NOTHING,N_DECLOOP,NULL,NULL,NULL);
		}
        ;

varlist 
		: identifier varloop
		{
			$$ = string_node($1,N_VARLIST,$1,$2,NULL);	
		}
		;

varloop
		: COMMA identifier varloop
		{
			$$ = string_node($2,N_VARLOOP,$2,$3,NULL);	
		}
		| 
		{
			$$ = int_node(NOTHING,N_VARLOOP,NULL,NULL,NULL);
		}
		;

subprograms
		: subloop
		{
			$$ = int_node(NOTHING,N_SUBPROGRAMS,$1,NULL,NULL);	
		}
		;

subloop 
		: func subloop
		{
			$$ = int_node(NOTHING,N_SUBLOOP,$1,$2,NULL);	
		}
		| 
		{
			$$ = int_node(NOTHING,N_SUBLOOP,NULL,NULL,NULL);
		}
		;

func
 		: PROCEDURE identifier funcbody
		{
			savefunc($3);
		} 
		{
			$$ = string_node($2,N_FUNC,$2,$3,NULL);
		}
		| FUNCTION identifier funcbody
		{	
			savefunc($3);
		} 
		{
			$$ = string_node($2,N_FUNC,$2,$3,NULL);	
		}
		;

funcbody 
		: formalpars block
		{
			$$ = int_node(NOTHING,N_FUNCBODY,$1,$2,NULL);	
		}
		;

formalpars
		: LPAREN RPAREN
		{
			$$ = int_node(NOTHING,N_FORMALPARS,NULL,NULL,NULL);	
		}
		| LPAREN formalparlist RPAREN  
		{
			$$ = int_node(NOTHING,N_FORMALPARS,$2,NULL,NULL);	
		}
		;

formalparlist
		: formalparitem formalparlist_loop
		{
			$$ = int_node(NOTHING,N_FORMALPARLIST,$1,$2,NULL);
		}
		;

formalparlist_loop
		: COMMA formalparitem formalparlist_loop
		{
			$$ = int_node(NOTHING,N_FORMALPARLIST_LOOP,$2,$3,NULL);	
		}
		| 
		{
			$$ = int_node(NOTHING,N_FORMALPARLIST_LOOP,NULL,NULL,NULL);
		}
		;

formalparitem
		: IN identifier
		{
			$$ = string_node($2,N_FORMALPARITEM,$2,NULL,NULL);
		}
		| INOUT identifier
		{
			$$ = string_node($2,N_FORMALPARITEM,$2,NULL,NULL);	
		}
		;

brack_or_stat
		: brackets_seq 
		{
			$$ = int_node(NOTHING,N_BRACK_OR_STAT,$1,NULL,NULL);	
		}
		| statement
		{
			$$ = int_node(NOTHING,N_BRACK_OR_STAT,$1,NULL,NULL);	
		}
		;

brackets_seq 
		: LBRACK sequence RBRACK
		{
			$$ = int_node(NOTHING,N_BRACKETS_SEQ,$2,NULL,NULL);	
		}
		;

sequence 
		: statement seqloop
		{
			$$ = int_node(NOTHING,N_SEQUENCE,$1,$2,NULL);	
		}
		;

seqloop 
		: SEMICOLON statement seqloop 
		{
			$$ = int_node(NOTHING,N_SEQLOOP,$2,$3,NULL);	
		}
		| 
		{
			$$ = int_node(NOTHING,N_SEQLOOP,NULL,NULL,NULL);	
		}
		;

statement
        : assignment_stat 
		{
			$$ = int_node(NOTHING,N_STATEMENT,$1,NULL,NULL);
		}
		| if_stat
		{
			$$ = int_node(NOTHING,N_STATEMENT,$1,NULL,NULL);
		}
		| while_stat
		{
			$$ = int_node(NOTHING,N_STATEMENT,$1,NULL,NULL);
		}
		| double_while_stat
		{
			$$ = int_node(NOTHING,N_STATEMENT,$1,NULL,NULL);
		}
		| loop_stat
		{
			$$ = int_node(NOTHING,N_STATEMENT,$1,NULL,NULL);
		}
		| forcase_stat
		{
			$$ = int_node(NOTHING,N_STATEMENT,$1,NULL,NULL);
		}
		| incase_stat
		{
			$$ = int_node(NOTHING,N_STATEMENT,$1,NULL,NULL);
		}
		| exit_stat
		{
			$$ = int_node(NOTHING,N_STATEMENT,$1,NULL,NULL);
		}
		| return_stat
		{
			$$ = int_node(NOTHING,N_STATEMENT,$1,NULL,NULL);	
		}
		| print_stat
		{
			$$ = int_node(NOTHING,N_STATEMENT,$1,NULL,NULL);	
		}
		| input_stat
		{
			$$ = int_node(NOTHING,N_STATEMENT,$1,NULL,NULL);	
		}
		| call_stat 
		{
			$$ = int_node(NOTHING,N_STATEMENT,$1,NULL,NULL);	
		}
		| 
		{
			$$ = int_node(NOTHING,N_STATEMENT,NULL,NULL,NULL);
		}
		;

assignment_stat
		: identifier ASSIGN expression
		{
			$$ = string_node($1,N_ASSIGNMENT_STAT,$1,$3,NULL);	
		}
		;
	
if_stat		
		: IF LPAREN condition RPAREN brack_or_stat elsepart
		{
			$$ = int_node(NOTHING,N_IF_STAT,$3,$5,$6);	
		}	 
		;

elsepart
		: ELSE brack_or_stat
		{
			$$ = int_node(NOTHING,N_ELSEPART,$2,NULL,NULL);	
		}
		| 
		{
			$$ = int_node(NOTHING,N_ELSEPART,NULL,NULL,NULL);
		}
		;
	
while_stat
        : WHILE LPAREN condition RPAREN brack_or_stat
		{	
			$$ = int_node(NOTHING,N_WHILE_STAT,$3,$5,NULL);	
		}
        ;

double_while_stat
		: DOUBLEWHILE LPAREN condition RPAREN brack_or_stat ELSE brack_or_stat
		{
			$$ = int_node(NOTHING,N_DOUBLE_WHILE_STAT,$3,$5,$7);	
		}
        ;

loop_stat
		: LOOP brack_or_stat
		{
			$$ = int_node(NOTHING,N_LOOP_STAT,$2,NULL,NULL);	
		}
        ;

forcase_stat
	    : FORCASE when_loop DEFAULT COLON brack_or_stat
		{
			$$ = int_node(NOTHING,N_FORCASE_STAT,$2,$5,NULL);	
		}
        ;

incase_stat 
        : INCASE  when_loop 
		{
			$$ = int_node(NOTHING,N_INCASE_STAT,$2,NULL,NULL);	
		}
        ;
  
when_loop    
		: when_stat when_loop
		{
			$$ = int_node(NOTHING,N_WHEN_LOOP,$1,$2,NULL);	
		}
		| 
		{
			$$ = int_node(NOTHING,N_WHEN_LOOP,NULL,NULL,NULL);	
		}
        ;

when_stat 		
		: WHEN COLON LPAREN condition RPAREN COLON brack_or_stat
		{
			$$ = int_node(NOTHING,N_WHEN_STAT,$4,$7,NULL);	
		}
		;

exit_stat 
		: EXIT
		{
			$$ = int_node(NOTHING,N_EXIT_STAT,NULL,NULL,NULL);	
		}
		;

return_stat 
		: RETURN LPAREN expression RPAREN
		{
			$$ = int_node(NOTHING,N_RETURN_STAT,$3,NULL,NULL); 
		}
		;

print_stat 
		: PRINT LPAREN expression RPAREN
		{
			$$ = int_node(NOTHING,N_PRINT_STAT,$3,NULL,NULL); 
		}
		;

input_stat		
        : INPUT LPAREN identifier RPAREN
		{
			$$ = string_node($3,N_INPUT_STAT,$3,NULL,NULL); 
		}
		;
		
call_stat
		: CALL identifier actualpars
		{
			$$ = string_node($2,N_CALL_STAT,$2,$3,NULL); 
		}
		;

actualpars 
		: LPAREN  RPAREN
		{
			$$ = int_node(NOTHING,N_ACTUALPARS,NULL,NULL,NULL);
		}
		| LPAREN actualparlist RPAREN 
		{
			$$ = int_node(NOTHING,N_ACTUALPARS,$2,NULL,NULL);	
		}
		;

actualparlist
		: actualparitem actloop
		{
			$$ = int_node(NOTHING,N_ACTUALPARLIST,$1,$2,NULL);	
		}
		;

actloop		
		: COMMA actualparitem actloop
		{
			$$ = int_node(NOTHING,N_ACTLOOP,$2,$3,NULL);
		}
		| 
		{
			$$ = int_node(NOTHING,N_ACTLOOP,NULL,NULL,NULL);
		}
		;

actualparitem		
		: IN expression
		{
			$$ = int_node(NOTHING,N_ACTUALPARITEM,$2,NULL,NULL);
		}
		| INOUT identifier
		{
			$$ = int_node($2,N_ACTUALPARITEM,$2,NULL,NULL);
		}
		;

condition
		: boolterm booltloop
		{
			$$ = int_node(NOTHING,N_CONDITION,$1,$2,NULL);	 
		}
		;

booltloop		
		: OR boolterm booltloop
		{
			$$ = int_node(NOTHING,N_BOOLTLOOP,$2,$3,NULL);	
		}
		| 
		{
			$$ = int_node(NOTHING,N_BOOLTLOOP,NULL,NULL,NULL);	
		}
		;    

boolterm		
		: boolfactor boolfloop
		{
			$$ = int_node(NOTHING,N_BOOLTERM,$1,$2,NULL);	
		}
		;

boolfloop	
		: AND boolfactor boolfloop
		{
			$$ = int_node(NOTHING,N_BOOLFLOOP,$2,$3,NULL);  
		}
		| 
		{
			$$ = int_node(NOTHING,N_BOOLFLOOP,NULL,NULL,NULL);
		}
		;   

boolfactor		
		: NOT LSQUARE_BRACK condition RSQUARE_BRACK
		{
			$$ = int_node(NOTHING,N_BOOLFACTOR,$3,NULL,NULL);
		}
		| LSQUARE_BRACK condition RSQUARE_BRACK
		{
			$$ = int_node(NOTHING,N_BOOLFACTOR,$2,NULL,NULL);
		}
		| expression relational_oper expression 
		{
			$$ = int_node(NOTHING,N_BOOLFACTOR,$1,$2,$3); 
		}
		;

expression 		
		: optional_sign term addopertermloop
		{
			$$ = int_node(NOTHING,N_EXPRESSION,$1,$2,$3);
		}		
		;

addopertermloop		
		: add_oper term addopertermloop
		{
			$$ = int_node(NOTHING,N_ADDOPERTERMLOOP,$1,$2,$3);
		}		
	    | 
	    {
			$$ = int_node(NOTHING,N_ADDOPERTERMLOOP,NULL,NULL,NULL);
		}
	  ;

term		
		: factor  mulopertermloop
		{
			$$ = int_node(NOTHING,N_TERM,$1,$2,NULL);
		}
		;
				
mulopertermloop		
		: mul_oper factor mulopertermloop 
		{
			$$ = int_node(NOTHING,N_MULOPERTERMLOOP,$1,$2,$3);
			}
		| 
		{
			$$ = int_node(NOTHING,N_MULOPERTERMLOOP,NULL,NULL,NULL);
		}
		;	

factor		
		: DEC_CONST
		{
			$$ = int_node($1,N_FACTOR,NULL,NULL,NULL );
		}
		| LPAREN expression RPAREN	
		{
			$$ = int_node(NOTHING,N_FACTOR,$2,NULL,NULL);
		}
		| identifier idtail
		{
			$$ = int_node(NOTHING,N_FACTOR,$1,$2,NULL);
		}
		;
		
idtail
		: actualpars
		{
			$$ = int_node(NOTHING,N_IDTAIL,$1,NULL,NULL);
		}
		| 
		{
			$$ = int_node(NOTHING,N_IDTAIL,NULL,NULL,NULL);
		}		
		;

relational_oper
        : EQUAL
		    {
				$$ = string_node("==",N_RELATIONAL_OPER,NULL,NULL,NULL);
			}  
        | L_THAN
		    {
				$$ = string_node("<",N_RELATIONAL_OPER,NULL,NULL,NULL);
			}  
        | L_EQ_THAN
		    {
				$$ = string_node("<=",N_RELATIONAL_OPER,NULL,NULL,NULL);
			}  
        | NEQUAL
	     	{
				$$ = string_node("<>",N_RELATIONAL_OPER,NULL,NULL,NULL);
			}  
        | G_EQ_THAN
	    	{
				$$ = string_node(">=",N_RELATIONAL_OPER,NULL,NULL,NULL);
			}  
        | G_THAN
	    	{
				$$ = string_node(">",N_RELATIONAL_OPER,NULL,NULL,NULL);
			}  
        ;

add_oper
        : PLUS
		{
			$$ = string_node("+",N_ADD_OPER,NULL,NULL,NULL);
	    }
        | MINUS
		{
		    $$ = string_node("-",N_ADD_OPER,NULL,NULL,NULL);
	    } 
        ;

mul_oper
        : STAR
		{
			$$ = string_node("*",N_MUL_OPER,NULL,NULL,NULL);
	    }
        | DIV
		{
			$$ = string_node("/",N_MUL_OPER,NULL,NULL,NULL);
	    }
        ;

optional_sign 
        : add_oper
		{
		   $$ = int_node(NOTHING,N_OPTIONAL_SIGN,$1,NULL,NULL);
	    }
		| 
		{
		   $$ = int_node(NOTHING,N_OPTIONAL_SIGN,NULL,NULL,NULL);
	    }
		;

%%


TERNARY_TREE int_node(int iVal, int case_identifier, TERNARY_TREE p1,TERNARY_TREE p2, TERNARY_TREE p3)
{
    TERNARY_TREE t;
    t = (TERNARY_TREE)malloc(sizeof(TREE_NODE));
    t->item = iVal;
    t->nodeIdentifier = case_identifier;
    t->first = p1;
    t->second = p2;
    t->third = p3;
}


TERNARY_TREE string_node(char *sVal, int case_identifier, TERNARY_TREE p1, TERNARY_TREE p2, TERNARY_TREE p3)
{
    TERNARY_TREE t;
    t = (TERNARY_TREE)malloc(sizeof(TREE_NODE));
    t->stem = sVal;
    t->nodeIdentifier = case_identifier;
    t->first = p1;
    t->second = p2;
    t->third = p3;
}


#ifdef DEBUG
void PrintTree(TERNARY_TREE t)
{
    static unsigned depth;
    static unsigned previous;
    unsigned i;

    if (t == NULL) return;
    
    fprintf(stderr, "%3d %3d\t", depth, depth - previous);
    previous = depth;
    
    for (i = depth; i--;) fprintf(stderr, "| ");
    switch (t->nodeIdentifier) {
    case N_PROGRAM:
        
        fprintf(stderr, "PROGRAM : %s\n", symTab[t->item]->identifier);
        break;
    		
    case N_RELATIONAL_OPER:
	case N_ADD_OPER:
    case N_MUL_OPER:
        fprintf(stderr, "%s : %s\n", NodeName[t->nodeIdentifier], t->stem);
        return;

    default:
        
        if (t->nodeIdentifier >= 0 && t->nodeIdentifier < sizeof(NodeName)) {
            fprintf(stderr, "%s\n", NodeName[t->nodeIdentifier]);
        } else {
            fprintf(stderr, "UNKNOWN: %d\n", t->nodeIdentifier);
        }
        
        if (t->item > 0 && t->item < SYMTABSIZE) {
            if (symTab[t->item]->identifier) {
                fprintf(stderr, "%3d   1\t", ++depth);
                previous = depth;
                for (i = depth--; i--;) fprintf(stderr, "| ");
                fprintf(stderr, "IDENTIFIER : %s\n", symTab[t->item]->identifier);
            }
        }
        break;
    }
    
    ++depth;
    PrintTree(t->first);
    PrintTree(t->second);
    PrintTree(t->third);
    --depth;
}
#endif


int column;
extern int column;
extern void yyrestart( FILE *input_file );
extern FILE *new_file; 
int yydebug;


FILE *Source; 
int main(int argc, char *argv[])
{
if (argc!=2) printf("\nUsage: ph_2 <input file name> \n");
	else
		if ((new_file=fopen(argv[1],"r"))==NULL) 
			printf("\n<%s> not found.\n",argv[1]);
		else 
			{
				yyrestart(new_file); 
				return yyparse();
				fclose(new_file);
			}
symbol_table newst;
newst=create_st();
int yydebug=1;
return yyparse();
}


void yyerror(s)
char *s;
{
    fflush(stdout);
    printf("\nLine <%d>: %s\n",line,s);
    freestack_st();
	exit(1);
}


static void
yyprint (file, type, value)
     FILE *file;
     int type;
     YYSTYPE value;
{
    if (type == IDENTIFIER)
    fprintf (stderr," = %s", value.name);
 
}


void printerr(errconbr errmess)
{
	if (errmess!=NULL)
	{
		line=errmess->line;
		yyerror(errmess->mess);
	}
}


char *GetYYText(void)
{
char *ch;
ch=(char *)malloc(sizeof(char)*(strlen(yytext)+1));
strcpy(ch,yytext);
return ch;
}


void savefunc(funcdef func)
{
if (func->error!=NULL)
  {
	char *errmess=(char *)malloc(sizeof(char)*100);
	switch(func->error->code){
		case FPAR_NOT_FOUND		: sprintf(errmess,"Formal parameter '%s' not found",func->error->formal_pname); break;
		case FPAR_MORETONE		: sprintf(errmess,"Formal parameter '%s' is declared more than one times",func->error->formal_pname); break;
		case FPAR_NOT_FPARLIST	: sprintf(errmess,"Parameter '%s' not in formal parameter list",func->error->formal_pname); break;
	}
	yyerror(errmess);
 }
else if (!enter(proc_st,func->entr)) yyerror("Function redefinition");
}