#pragma once

#include "cStmtNode.h"
#include "cExprNode.h"

#include <string>

class cAssignNode : public cStmtNode
{
protected:
    std::string m_varName;

public:
    cAssignNode(cExprNode *expr, std::string varName);
    
    cExprNode* GetExpr();

    virtual void Traverse();
};