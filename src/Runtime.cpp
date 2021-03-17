#include "Runtime.h"

Runtime::Runtime() : variables()
{

}

int Runtime::GetVariable(std::string identifier)
{
    if (this->variables.count(identifier))
    {
        return this->variables[identifier];
    }
    else
    {
        return 0;
    }
}

void Runtime::SetVariable(std::string identifier, int value)
{
    this->variables[identifier] = value;
}
