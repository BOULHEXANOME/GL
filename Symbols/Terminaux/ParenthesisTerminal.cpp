//
// Created by hdelval on 08/03/16.
//

#include <iostream>
#include "ParenthesisTerminal.h"

ParenthesisTerminal::ParenthesisTerminal(const TypeOfParenthesis &aTypeOfParenthesis)
{
	typeOfParenthesis = aTypeOfParenthesis;
	if (typeOfParenthesis == opening)
		symbolType = OPENPARENTHESIS;
	else
		symbolType = CLOSEPARENTHESIS;
}
