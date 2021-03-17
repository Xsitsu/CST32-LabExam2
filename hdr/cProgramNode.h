#pragma once

#include "cAstNode.h"
#include "cStmtsNode.h"

class cProgramNode : public cAstNode
{
protected:

public:
    cProgramNode(cStmtsNode *stmts);
};