#pragma once

#include <string>

#include "lex.h"

#include "cExprNode.h"

class cVarRefNode : public cExprNode
{
protected:
    std::string m_varName;

public:
    cVarRefNode(std::string varName) : cExprNode()
    {
        this->m_varName = varName;
    }

    virtual float GetValue()
    {
        return runtime->GetVariable(this->m_varName);
    }
};