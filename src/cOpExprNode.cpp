#include "cOpExprNode.h"

cOpExprNode::cOpExprNode(cExprNode *left, cExprNode *right, int op_code) : cExprNode()
{
    this->m_op_code = op_code;
    this->AddChild(left);
    this->AddChild(right);
}

cExprNode cOpExprNode::*GetLeft()
{
    return static_cast<cExprNode*>(this->GetChild(0));
}

cExprNode cOpExprNode::*GetRight()
{
    return static_cast<cExprNode*>(this->GetChild(1));
}


float cOpExprNode::GetValue()
{
    float lval = this->GetLeft()->Getvalue();
    float rval = this->GetRight()->GetValue();

    if (this->m_op_code == '$')
    {
        if (lval > rval)
        {
            return lval;
        }
        return rval;
    }
    else if (this->m_op_code == '^')
    {
        return lval * (lval + rval);
    }
    else if (this->m_op_code == ':')
    {
        return (lval + 1) * rval;
    }
    else if (this->m_op_code == '#')
    {
        return lval / (rval + 1);
    }
    return -1;
}
