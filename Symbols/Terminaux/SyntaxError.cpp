//
// Created by hdelval on 09/03/16.
//

#include "SyntaxError.h"

SyntaxError::SyntaxError(const std::string &wrongSymbol)
{
	this->symbolType = ERROR;
	theWrongSymbol = wrongSymbol;
}
