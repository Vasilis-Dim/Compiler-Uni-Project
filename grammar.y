%{
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "sym_tab.h"
#define YYERROR_VERBOSE
#define YYPRINT(file, type, value)   yyprint (file, type, value) 
extern char *yytext;
%}

%union
{
char *name;
}

%token CALL
%token ASSIGN
%token DEC_CONST
%token IDENTIFIER 
%token NOT AND OR 
%token STRING_LITERAL
%token PLUS MINUS STAR DIV
%token IN INOUT INPUT PRINT
%token SEMICOLON COMMA COLON
%token PROGRAM DECLARE DEFAULT FUNCTION PROCEDURE
%token L_THAN G_THAN EQUAL L_EQ_THAN G_EQ_THAN NEQUAL
%token LPAREN RPAREN LSQUARE_BRACK RSQUARE_BRACK LBRACK RBRACK
%token ELSE IF RETURN WHILE DOUBLEWHILE LOOP FORCASE INCASE WHEN EXIT

%start program

%type <name> identifier
%type <idlist> varlist 

%%

program
		: PROGRAM identifier block
		;

identifier
		: IDENTIFIER
			{
				$$=(char *)malloc(sizeof(char)*strlen(yytext));
				strcpy($$,yytext);
			}
		;

block
        : LBRACK declarations subprograms sequence RBRACK
		;

declarations
        : DECLARE varlist SEMICOLON decloop	
		;

decloop
		:declarations decloop
		| // empty
        ;

varlist 
		: identifier varloop
		;

varloop
	: COMMA identifier varloop
	| //empty
	;
	
subprograms
		: subloop
		;

subloop 
		: func subloop
		| //empty
		;

func
 		: PROCEDURE identifier funcbody
		| FUNCTION identifier funcbody
		;

funcbody 
		: formalpars block
		;

formalpars
		: LPAREN RPAREN
		| LPAREN formalparlist RPAREN  
		;

formalparlist
		: formalparitem formalparlist_loop
		;

formalparlist_loop
		: COMMA formalparitem formalparlist_loop
		| //empty
		;

formalparitem
		: IN identifier
		| INOUT identifier
		;

brack_or_stat
		: brackets_seq 
		| statement
		;

brackets_seq 
		: LBRACK sequence RBRACK
		;

sequence 
		: statement seqloop
		;

seqloop 
		: SEMICOLON statement seqloop
		| //empty
		;

statement
        : assignment_stat 
		| if_stat
		| while_stat
		| double_while_stat
		| loop_stat
		| forcase_stat
		| incase_stat
		| exit_stat
		| return_stat
		| print_stat
		| input_stat
		| call_stat 
		| //empty
		;

assignment_stat
		: identifier ASSIGN expression
		;
	
if_stat		
		: IF LPAREN condition RPAREN brack_or_stat elsepart	 
		;

elsepart
		: ELSE brack_or_stat
		| //empty
		;

while_stat
          : WHILE LPAREN condition RPAREN brack_or_stat
          ;

double_while_stat
		  : DOUBLEWHILE LPAREN condition RPAREN brack_or_stat ELSE brack_or_stat
          ;

loop_stat
		  : LOOP brack_or_stat
          ;

forcase_stat
		  : FORCASE when_loop DEFAULT COLON brack_or_stat
          ;

incase_stat
          : INCASE  when_loop 
          ;
  
when_loop
		: when_stat when_loop
		| //empty
        ;

when_stat 		
		: WHEN COLON LPAREN condition RPAREN COLON brack_or_stat
		;

exit_stat
		: EXIT
		;

return_stat
		: RETURN LPAREN expression RPAREN
		;

print_stat
		: PRINT LPAREN expression RPAREN
		;

input_stat		
        : INPUT LPAREN identifier RPAREN
		;

call_stat
		: CALL identifier actualpars
		;

actualpars 
		: LPAREN  RPAREN
		| LPAREN actualparlist RPAREN 
		;

actualparlist
		: actualparitem actloop
		;

actloop		
		: COMMA actualparitem actloop
		| //empty
		;

actualparitem		
		: IN expression
		| INOUT identifier
		;

condition
		: boolterm booltloop
		;

booltloop		
		: OR boolterm booltloop
		| //empty
		;    

boolterm		
		: boolfactor  boolfloop
		;

boolfloop	
		: AND boolfactor boolfloop
		| //empty
		;   

boolfactor		
		: NOT LSQUARE_BRACK condition RSQUARE_BRACK
		| LSQUARE_BRACK condition RSQUARE_BRACK
		| expression relational_oper expression
		;

expression 		
		: optional_sign term addopertermloop		
		;

addopertermloop		
	  : add_oper term addopertermloop		
	  | //empty
	  ;

term		
		: factor  mulopertermloop
		;
				
mulopertermloop		
		: mul_oper factor mulopertermloop
		| //empty
		;	

factor		
		: DEC_CONST
		| LPAREN expression RPAREN		
		| identifier idtail
		;
		
idtail
		: actualpars
		| //empty
		;

relational_oper
        : EQUAL
        | L_THAN
        | L_EQ_THAN
        | NEQUAL
        | G_EQ_THAN
        | G_THAN
        ;

add_oper
        : PLUS
        | MINUS
        ;

mul_oper
        : STAR
        | DIV
        ;

optional_sign 
        : add_oper
		| //empty
		;

%%

int column;
extern int column;
extern void yyrestart( FILE *input_file );
extern FILE *new_file; 
int yydebug;

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

int yyerror(s)
char *s;
{
        fflush(stdout);
        printf("\n%*s\n%*s\n", column, "^", column, s);
		return 1;
		
}

static int
yyprint (file, type, value)
     FILE *file;
     int type;
     YYSTYPE value;
{
  if (type == IDENTIFIER)
    fprintf (stderr," = %s", value.name);
  return 1;
}
