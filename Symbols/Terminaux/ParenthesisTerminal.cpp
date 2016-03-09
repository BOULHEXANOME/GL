//
// Created by hdelval on 08/03/16.
//

#include <iostream>
#include "ParenthesisTerminal.h"

int ParenthesisTerminal::getType()
{
    if(this->typeOfParenthesis == TypeOfParenthesis::closing)
        return CLOSEPARENTHESIS;
    else if(this->typeOfParenthesis == TypeOfParenthesis::opening)
        return OPENPARENTHESIS;
    else
    {
        std::cerr << "Parenthesis don't have type (opening or closing)." << std::endl;
        return ERROR;
    }
}
