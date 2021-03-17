#pragma once

#include <vector>

class cAstNode
{
private:
    std::vector<cAstNode*> m_children;

protected:
    void AddChild(cAstNode *node);
    cAstNode* GetChild(int index);
    int NumChildren();

public:
    cAstNode();

    virtual void Traverse();
};