#pragma once

#include "cStmtNode.h"

class cExprNode : public cStmtNode
{
protected:

public:
    cExprNode();
    float GetValue();
};