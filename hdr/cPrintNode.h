#pragma once

#include "cStmtNode.h"

class cPrintNode : public cStmtNode
{
protected:

public:
    cPrintNode(cExprNode *expr);

    virtual void Traverse();

    cExprNode *GetExpr();
};