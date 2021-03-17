#pragma once

#include "cExprNode.h"

#include "lex.h"

class cFloatExprNode : public cExprNode
{
    public:
        cFloatExprNode(float value) : cExprNode()
        {
            m_value = value;
        }

        virtual float GetValue() { return m_value; }

    protected:
        float m_value;
};
