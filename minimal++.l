%{
#include <stdio.h>
#include <stdlib.h> 
#include <malloc.h> 
#include <string.h>
#include "gener.h"
#include "sym_tab.h"
#include "int_code.h"
#include "y.tab.h"
int stringtoint;
int line;
int block_num;
int yycopy;
void count();
void add_bloc_number();
void reduce_bloc_number();
void multi_line_comment();
void one_line_comment();
FILE *new_file;
%}

L                  [A-Za-z]
D                  [0-9]
N                  [1-9]
C				   "!"|"@"|"#"|"$"|"%"|"^"|"&"|"_"|"-"

identifier          {L}({L}|{D})*      
dec_const           0|{N}{D}*
invalid_dec_const   ({D}|{N}){L}
                                  
blank          			[ \t\r]+
invalid_identifier	{D}|{C}(({L}|{D})*|{L})
invalid_keyword 		{C}({L}|{D})+

%%

"program"           {count();  return(PROGRAM); }
                        
"declare"           {count();  return(DECLARE); }
                  
"if"                {count();  return(IF); }
                         
"else"              {count(); return(ELSE); }

"while"             {count(); return(WHILE); }

"doublewhile"       {count(); return(DOUBLEWHILE); }

"loop"              {count(); return(LOOP); }

"exit"              {count(); return(EXIT); }

"forcase"           {count(); return(FORCASE); }

"incase"            {count(); return(INCASE); }

"when"              {count(); return(WHEN); }

"default"           {count(); return(DEFAULT); }

"not"               {count(); return(NOT); }

"and"               {count(); return(AND); }

"or"                {count(); return(OR); }

"function"          {count(); return(FUNCTION); }

"procedure"         {count(); return(PROCEDURE); }

"call"              {count(); return(CALL); }

"return"            {count(); return(RETURN); }

"in"                {count(); return(IN); }

"inout"             {count();  return(INOUT); }

"input"             {count(); return(INPUT); }

"print"             {count(); return(PRINT); }


\"(\\.|[^\\"])*\"		{count(); return(STRING_LITERAL); }

{dec_const}               {char *yycopy=strdup(yytext); count(); stringtoint=atoi(yycopy);if(stringtoint<(-65535)|| stringtoint>65535){
				                              		  printf("dec_const %d in line %d not an acceptable value\n",stringtoint,line);}else{
						                                printf("Found dec_const %s at line %d\n", yycopy,line);
			                              			   return(DEC_CONST);}}


{identifier}	          {char *yycopy=strdup(yytext); count(); if(strlen(yycopy)>30){
						   printf("identifier %s in line %d not valid(longer than 30 characters)\n",yycopy,line);}
						   else{printf("found %s \n", yycopy); 
                           return(IDENTIFIER);}}




"+"           {count(); return(PLUS);}

"-"           {count(); return(MINUS);}

"*"           {count(); return(STAR);}

"/"           {count(); return(DIV);}

"<"	          {count(); return(L_THAN);}

">"	         {count(); return(G_THAN);}

"="	         {count(); return(EQUAL);}

"<="         {count(); return(L_EQ_THAN);}

">="		     {count(); return(G_EQ_THAN);}

"<>"		     {count(); return(NEQUAL);}

":="	       {count(); return(ASSIGN);}

"("	         {count(); return(LPAREN);}

")"	         {count(); return(RPAREN);}

"["          {count(); return(LSQUARE_BRACK);}

"]"          {count(); return(RSQUARE_BRACK);}

"{"          {count(); return(LBRACK);}

"}"          {count(); return(RBRACK);}

";"          {count(); return(SEMICOLON);}

","          {count(); return(COMMA);}

":"          {count(); return(COLON);}

"//"         {one_line_comment();}

"/*"         {multi_line_comment();}

{blank}      {count();}    

{invalid_dec_const}		 {count(); printf("invalid dec_const %s at line %d\n", yycopy, line);}
						  

{invalid_keyword}	  	 {count(); printf("invalid keyword %s at line %d\n", yycopy, line);}
						  

{invalid_identifier}	 {count(); printf("invalid identifier %s at line %d\n", yycopy, line);}
						 

.				             	 {count(); printf("unexpected character %s at line %d\n", yycopy, line);}
					


%%

int yywrap()
{
	return 1;
}


void count()
{
        int i;
        for(i=0;yytext[i]!='\0';i++)
        if(yytext[i]=='\n')
        {
          line++;    
        }   
}

void multi_line_comment()
{

    int c;
  
  for (;;)
    {   
   while((c=input())!='*' && c!=EOF)
     { 
	  if (c=='\n') 
	    {
		 line++;
		 
	    }
      }
	     if (c=='*')  
        {
          
          while ((c=input()) =='*')  
		      { 
	           if (c=='\n') 
	           {
		            line++;
		         }
           }
		      
		     
		  if (c=='/')
            {
			 break;
            }    
		}
      
	  if (c==EOF)
        {
         printf("ERROR: eof in comment\n");
         break;
        }
    }  
}

void one_line_comment()
{
  int c;
  while(c=input()!='\n')
  {
     
  }
  line++;
}


void add_bloc_number()
{
  block_num=block_num+1;
} 

void reduce_bloc_number()
{
 block_num=block_num-1;
}