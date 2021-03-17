%{
//**************************************
// lang.y
//
// Parser definition file. bison uses this file to generate the parser.
//
// Author: Jacob Locke
//

#include <iostream>
#include <string>

#include "astnodes.h"
#include "lex.h"

%}

%locations

 /* union defines the type for lexical values */
%union{
    int             int_val;
    float           float_val;
    std::string*    str_val;
    }

%{
    int yyerror(const char *msg);

    cAstNode *yyast_root;

%}

%start  program

%token <str_val>    IDENTIFIER
%token <int_val>    INT_VAL
%token <float_val>  FLOAT_VAL

%token JUNK_TOKEN

%type <program_node> program
%type <stmts_node> stmts
%type <stmt_node> stmt
%type <expr_node> expr

%%




program: stmts                  { $$ = new cProgramNode($1);
                                  yyast_root = $$;
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }

stmts:      stmts stmt          { $$ = $1; $$->Insert($2); }
        |   stmt                { $$ = new cStmtsNode($1); }

stmt:       expr '!'            { $$ = $1; }
        |   POP '@' IDENTIFIER  { $$ = new cPopNode(*($3)); }
        |   QUIT                { $$ = new cQuitNode(); }
        |   error ';'           {}                      

expr:       INT_VAL             { $$ = new cIntExprNode($1); }
        |   '+'                 { $$ = new cOpExprNode('+'); }
        |   '-'                 { $$ = new cOpExprNode('-'); }
        |   '*'                 { $$ = new cOpExprNode('*'); }
        |   '/'                 { $$ = new cOpExprNode('/'); }

%%

// Function to format error messages
int yyerror(const char *msg)
{
    std::cerr << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}
