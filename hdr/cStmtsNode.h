#pragma once

#include "cAstNode.h"
#include "cStmtNode.h"

class cStmtsNode : public cAstNode
{
protected:

public:
    cStmtsNode(cStmtNode *stmt);

    void Insert(cStmtNode *stmt);
};