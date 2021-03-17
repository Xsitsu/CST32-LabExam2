#include "cStmtsNode.h"

cStmtsNode::cStmtsNode(cStmtNode *stmt) : cAstNode()
{
    this->Insert(stmt);
}

void cStmtsNode::Insert(cStmtNode *stmt)
{
    this->AddChild(stmt);
}
