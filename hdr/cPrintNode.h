#pragma once

#include "cStmtNode.h"
#include "cExprNode.h"

class cPrintNode : public cStmtNode
{
protected:

public:
    cPrintNode(cExprNode *expr);

    virtual void Traverse();

    cExprNode *GetExpr();
};