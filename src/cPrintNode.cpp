#include "cPrintNode.h"

#include <stdio.h>

#include "lex.h"

cPrintNode::cPrintNode(cExprNode *expr) : cStmtNode()
{
    this->AddChild(expr);
}

void cPrintNode::Traverse()
{
    printf("%f\n", this->GetExpr()->GetValue());
    this->cAstNode::Traverse();
}

cExprNode* cPrintNode::GetExpr()
{
    return static_cast<cExprNode*>(this->GetChild(0));
}