#pragma once

#include "cExprNode.h"

class cOpExprNode : public cExprNode
{
protected:
    int m_op_code;

public:
    cOpExprNode(cExprNode *left, cExprNode *right, int op_code);

    cExprNode *GetLeft();
    cExprNode *GetRight();

    virtual float GetValue();
};