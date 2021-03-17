#pragma once

#include "cStmtNode.h"

class cQuitNode : public cStmtNode
{
protected:

public:
    cQuitNode();

    virtual void Traverse();
};