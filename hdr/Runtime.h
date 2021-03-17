#pragma once

#include <string>
#include <unordered_map>

class Runtime
{
protected:
    std::unordered_map<std::string, int> variables;

public:
    Runtime();

    int GetVariable(std::string identifier);
    void SetVariable(std::string identifier, int value);
};