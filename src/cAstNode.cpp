#include "cAstNode.h"

void cAstNode::AddChild(cAstNode *node)
{
    this->m_children.push_back(node);
}

cAstNode* cAstNode::GetChild(int index)
{
    if (index >= (int)this->m_children.size()) return nullptr;
    return this->m_children[index];
}

int cAstNode::NumChildren()
{
    return (int)this->m_children.size();
}

cAstNode::cAstNode() : m_children()
{

}

void cAstNode::Traverse()
{
    for (auto child : this->m_children)
    {
        child->Traverse();
    }
}