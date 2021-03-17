//**************************************
// lang.cpp
//
//
// Author: Jacob Locke
// Date: March 11. 2021
//


#include <iostream>

#include "lex.h"
#include "fileopen.h"

int main(int argc, char **argv)
{
    int result = 0;
    int open_result;
    std::cout << "Jacob Locke" << std::endl;

    open_result = fileopen(argc, argv, yyin);
    if (open_result != 0)
    {
        exit(open_result);
    }

    runtime = new Runtime();
    result = yyparse();
    if (yyast_root != nullptr)
    {
        if (result == 0)
        {
            yyast_root->Traverse();
        }
        else
        {
            std::cout << yynerrs << " Errors in compile\n";
        }
    }

    if (result == 0 && yylex() != 0)
    {
        std::cout << "Junk at end of program\n";
    }

    return result;
}