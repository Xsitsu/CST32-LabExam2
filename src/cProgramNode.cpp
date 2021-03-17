#include "cProgramNode.h"

cProgramNode::cProgramNode(cStmtsNode *stmts) : cAstNode()
{
    this->AddChild(stmts);
}