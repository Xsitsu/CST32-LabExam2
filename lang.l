%{
//**************************************
// lang.l
//
// scanner definition file. flex uses this file to create the scanner
//
// Author: Jacob Locke
//

#include <string>

#include "astnodes.h"
#include "lex.h"
#include "langparse.h"

#define DO_RETURN(a) { return (a); }
//#define DO_RETURN(a) { return Return(a); }

int Return(int val);

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno


whitespace                  [\t\n\r ]

variable                    [A-Z]
number                      [0-9]

%%
{whitespace}*                   ; /* ignore whitespace */
"//".*"\n"                      ; /* ignore C++ style comments */


 /*Punctuation*/
[\!\@\:\#\$\^;]                 {
                                    DO_RETURN(yytext[0]);
                                }

 /*Keywords*/
"quit"                           DO_RETURN(END);


 /*Others*/
 {variable}+                    {
                                    std::string *str = new std::string(yytext);
                                    yylval.str_val = str;
                                    DO_RETURN(IDENTIFIER);
                                }

 -?[number]+                    {
                                    yylval.int_val = atoi(yytext);
                                    DO_RETURN(INT_VAL);
                                }

-?[0-9]+\.[0-9]+                 {
                                    yylval.float_val = atof(yytext);
                                    DO_RETURN(FLOAT_VAL);
                                }

 /*Junk*/
 .                              DO_RETURN(JUNK_TOKEN);
%%

int Return(int val)
{
    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}
