#pragma once

#include "cStmtNode.h"

class cExprNode : public cStmtNode
{
protected:

public:
    cExprNode();
    virtual float GetValue();
};