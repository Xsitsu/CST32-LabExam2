#include "cPrintNode.h"

#include <iostream>

#include "lex.h"

cPrintNode::cPrintNode(cExprNode *expr) : cStmtNode()
{
    this->AddChild(expr);
}

void cPrintNode::Traverse()
{
    std::cout << this->GetExpr()->GetValue() << std::endl;
    this->cAstNode::Traverse();
}

cExprNode* cPrintNode::GetExpr()
{
    return static_cast<cExprNode*>(this->GetChild(0));
}