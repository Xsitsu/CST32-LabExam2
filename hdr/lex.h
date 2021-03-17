#pragma once

#include "cAstNode.h"

int yyparse();                          // parsing function
int yylex();                            // scanning function
extern char *yytext;                    // text of current token
extern int yylineno;                    // line number of input file
extern int yynerrs;                     // Num of compile errors
extern FILE *yyin;                      // FILE pointer for input
extern cAstNode *yyast_root;            // root of AST

extern Runtime *runtime;
