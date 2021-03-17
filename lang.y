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
    cProgramNode*   program_node;
    cStmtsNode*     stmts_node;
    cStmtNode*      stmt_node;
    cExprNode*      expr_node;
    }

%{
    int yyerror(const char *msg);

    cAstNode *yyast_root;

%}

%start  program

%token <str_val>    IDENTIFIER
%token <int_val>    INT_VAL
%token <float_val>  FLOAT_VAL

%token QUIT
%token JUNK_TOKEN

%type <program_node> program
%type <stmts_node> stmts
%type <stmt_node> stmt
%type <expr_node> expr
%type <expr_node> term
%type <expr_node> fact

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

stmt:       expr '!'            { $$ = new cPrintNode($1); }
        |   expr '@' IDENTIFIER { $$ = new cAssignNode($1, $3); }
        |   QUIT                { $$ = new cQuitNode(); }
        |   error ';'           {}                      

expr:       expr '$' term      { $$ = new cOpExprNode($1, $3, '$'); }
        |   expr '^' term      { $$ = new cOpExprNode($1, $3, '^'); }
        |   term               { $$ = $1; }

term:       term ':' fact      { $$ = new cOpExprNode($1, $3, ':'); }
        |   term '#' fact      { $$ = new cOpExprNode($1, $3, '#'); }
        |   fact               { $$ = $1; }

fact:       '(' expr ')'       { $$ = $2; }
        |   INT_VAL            { $$ = new cFloatExprNode($1); }
        |   FLOAT_VAL          { $$ = new cFloatExprNode($1); }
        |   IDENTIFIER         { $$ = new cVarRefNode($1); }

%%

// Function to format error messages
int yyerror(const char *msg)
{
    std::cerr << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}
