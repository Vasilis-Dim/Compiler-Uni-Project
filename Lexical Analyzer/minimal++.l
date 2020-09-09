%{
#include <stdio.h>
#include <stdlib.h>
#include "SymHashing.h"
#include "Defines.h"
FILE *new_file; 
int stringtoint;
void count();
void add_bloc_number();
void reduce_bloc_number();
void multi_line_comment();
void one_line_comment();
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

"else"	         	   	 {char *yycopy=strdup(yytext); count(); printf("found keyword else at line %d\n", line);  
                          addsym( yycopy, block_num ); return(ELSE); }

"if"			         {char *yycopy=strdup(yytext); count(); printf("found keyword if at line %d\n", line); 
                          addsym( yycopy, block_num ); return(IF); }

"return"		         {char *yycopy=strdup(yytext); count(); printf("found keyword return at line %d\n", line);  
                          addsym( yycopy, block_num ); return(RETURN); }

"while"			         {char *yycopy=strdup(yytext); count(); printf("found keyword while at line %d\n", line);  
                          addsym( yycopy, block_num ); return(WHILE); }

"program"			         {char *yycopy=strdup(yytext); count(); printf("found keyword program at line %d\n", line);  
                          addsym( yycopy, block_num ); return(PROGRAM); }

"declare"			         {char *yycopy=strdup(yytext); count(); printf("found keyword declare at line %d\n", line);  
                          addsym( yycopy, block_num ); return(DECLARE); }

"doublewhile"			         {char *yycopy=strdup(yytext); count(); printf("found doublewhile while at line %d\n", line);  
                          addsym( yycopy, block_num ); return(DOUBLEWHILE); }                        

"loop"			         {char *yycopy=strdup(yytext); count(); printf("found keyword loop at line %d\n", line);  
                          addsym( yycopy, block_num ); return(LOOP); }

"exit"			         {char *yycopy=strdup(yytext); count(); printf("found keyword exit at line %d\n", line);  
                          addsym( yycopy, block_num ); return(EXIT); }

"forcase"			         {char *yycopy=strdup(yytext); count(); printf("found keyword forcase at line %d\n", line);  
                          addsym( yycopy, block_num ); return(FORCASE); }

"incase"			         {char *yycopy=strdup(yytext); count(); printf("found keyword incase at line %d\n", line);  
                          addsym( yycopy, block_num ); return(INCASE); }

"when"			         {char *yycopy=strdup(yytext); count(); printf("found keyword when at line %d\n", line);  
                          addsym( yycopy, block_num ); return(WHEN); }

"default"			         {char *yycopy=strdup(yytext); count(); printf("found keyword default at line %d\n", line);  
                          addsym( yycopy, block_num ); return(DEFAULT); }

"not"			         {char *yycopy=strdup(yytext); count(); printf("found keyword not at line %d\n", line);  
                          addsym( yycopy, block_num ); return(NOT); }

"and"			         {char *yycopy=strdup(yytext); count(); printf("found keyword and at line %d\n", line);  
                          addsym( yycopy, block_num ); return(AND); }

"or"			         {char *yycopy=strdup(yytext); count(); printf("found keyword or at line %d\n", line);  
                          addsym( yycopy, block_num ); return(OR); }

"function"			         {char *yycopy=strdup(yytext); count(); printf("found function while at line %d\n", line);  
                          addsym( yycopy, block_num ); return(FUNCTION); }

"procedure"			         {char *yycopy=strdup(yytext); count(); printf("found keyword procedure at line %d\n", line);  
                          addsym( yycopy, block_num ); return(PROCEDURE); }

"call"			         {char *yycopy=strdup(yytext); count(); printf("found keyword call at line %d\n", line);  
                          addsym( yycopy, block_num ); return(CALL); }

"in"			         {char *yycopy=strdup(yytext); count(); printf("found keyword in at line %d\n", line);  
                          addsym( yycopy, block_num ); return(IN); }

"inout"			         {char *yycopy=strdup(yytext); count(); printf("found keyword inout at line %d\n", line);  
                          addsym( yycopy, block_num ); return(INOUT); }

"input"			         {char *yycopy=strdup(yytext); count(); printf("found keyword input at line %d\n", line);  
                          addsym( yycopy, block_num ); return(INPUT); }

"print"			         {char *yycopy=strdup(yytext); count(); printf("found keyword print at line %d\n", line);  
                          addsym( yycopy, block_num ); return(PRINT); }

\"(\\.|[^\\"])*\"		{char *yycopy=strdup(yytext); count(); printf("found literal string %s at line %d\n" ,yycopy, line); 
                           addsym( yycopy, block_num ); return(STRING_LITERAL); }

{dec_const}               {char *yycopy=strdup(yytext); count(); stringtoint=atoi(yycopy);if(stringtoint<(-65535)|| stringtoint>65535){
				                              		  printf("dec_const %d in line %d not an acceptable value\n",stringtoint,line);}else{
						                                printf("Found dec_const %s at line %d\n", yycopy,line);
			                              			  addsym( yycopy, block_num ); return(DEC_CONST);}}


{identifier}	          {char *yycopy=strdup(yytext); count(); if(strlen(yycopy)>30){
						   printf("identifier %s in line %d not valid(longer than 30 characters)\n",yycopy,line);}
						   else{printf("found %s at line %d\n", yycopy,line); 
                           addsym( yycopy, block_num ); return(IDENTIFIER);}}



"+"                       {char *yycopy=strdup(yytext); count(); printf("found symbol %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); return(PLUS);}

"-"                       {char *yycopy=strdup(yytext); count(); printf("found symbol %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); return(MINUS);}

"*"                       {char *yycopy=strdup(yytext); count(); printf("found symbol %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); return(STAR);}

"/"                       {char *yycopy=strdup(yytext); count(); printf("found symbol %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); return(DIV);} 

"<"                       {char *yycopy=strdup(yytext); count(); printf("found equation_symbol %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); return(L_THAN);}

">"                       {char *yycopy=strdup(yytext); count(); printf("found equation_symbol %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); return(G_THAN);}

"="                      {char *yycopy=strdup(yytext); count(); printf("found equation_symbol %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); return(EQUAL);}

"<="                      {char *yycopy=strdup(yytext); count(); printf("found equation_symbol %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); return(L_EQ_THAN);}

">="                      {char *yycopy=strdup(yytext); count(); printf("found equation_symbol %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); return(G_EQ_THAN);}

"<>"                      {char *yycopy=strdup(yytext); count(); printf("found equation_symbol %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); return(NEQUAL);}

":="                        {char *yycopy=strdup(yytext); count(); printf("found asign_symbol %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); return(ASSIGN);}

"("                       {char *yycopy=strdup(yytext); count(); printf("found %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); return(LPAREN);}

")"                       {char *yycopy=strdup(yytext); count(); printf("found %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); return(RPAREN);}

";"	                      {char *yycopy=strdup(yytext); count(); printf("found %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); return(SEMICOLON);}

","                       {char *yycopy=strdup(yytext); count(); printf("found %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); return(COMMA);}

":"	            		    	{char *yycopy=strdup(yytext); count(); printf("found %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); return(COLON);}

"["                       {char *yycopy=strdup(yytext); count(); printf("found %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); return(LSQUARE_BRACK);}

"]"                       {char *yycopy=strdup(yytext); count(); printf("found %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); return(RSQUARE_BRACK);}

"{"	                      {char *yycopy=strdup(yytext); count(); printf("found %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); add_bloc_number(block_num); return(LBRACK);}

"}"	                      {char *yycopy=strdup(yytext); count(); printf("found %s at line %d\n" ,yycopy, line);
                           addsym( yycopy, block_num ); reduce_bloc_number(block_num); return(RBRACK);}

"\n"                     {count();
                            return(ENDL);}

"//"                     {one_line_comment();}
"/*"                     {multi_line_comment();}
{blank}                  {count();}    

{invalid_dec_const}		 {char *yycopy=strdup(yytext); count(); printf("invalid dec_const %s at line %d\n", yycopy, line);
						  addsym( yycopy, block_num );}

{invalid_keyword}		 {char *yycopy=strdup(yytext); count(); printf("invalid keyword %s at line %d\n", yycopy, line);
						  addsym( yycopy, block_num );}

{invalid_identifier}	 {char *yycopy=strdup(yytext); count(); printf("invalid identifier %s at line %d\n", yycopy, line);
						  addsym( yycopy, block_num );}

.				     	 {char *yycopy=strdup(yytext); count(); printf("unexpected character %s at line %d\n", yycopy, line);
						  addsym( yycopy, block_num );}



%%

int yywrap()
{
	return 1;
}


void main(int argc, char *argv[]){
	int ret_val=1;
	
	if (argc!=2) printf("\nUsage: lexyy <input file name> \n");
	else
		if ((new_file=fopen(argv[1],"r"))==NULL) 
			printf("\n<%s> not found.\n",argv[1]);
		else{
			yyrestart(new_file); 
			while(ret_val!=0){
				ret_val=yylex();
			}
			fclose(new_file);
		}
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