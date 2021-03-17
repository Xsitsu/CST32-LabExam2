#include "cAssignNode.h"

#include "lex.h"

cAssignNode::cAssignNode(cExprNode *expr, std::string varName) : cStmtNode()
{
    this->m_varName = varName;
    this->AddChild(expr);
}

cExprNode* cAssignNode::GetExpr()
{
    return static_cast<cExprNode*>(this->GetChild(0));
}

void cAssignNode::Traverse()
{
    runtime->SetVariable(this->m_varName, this->GetExpr()->GetValue());
}
