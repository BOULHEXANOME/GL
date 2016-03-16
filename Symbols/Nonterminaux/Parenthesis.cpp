//
// Created by hdelval on 08/03/16.
//

#include "Parenthesis.h"

std::string Parenthesis::print() const
{
    return "(" + exprParenthesised->print() + ")";
}
