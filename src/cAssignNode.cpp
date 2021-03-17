#include "cAssignNode.h"

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
    // TODO: do the assign
}
