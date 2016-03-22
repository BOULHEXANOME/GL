//
// Created by hdelval on 08/03/16.
//

#ifndef GL_PARENTHESISTERMINAL_H
#define GL_PARENTHESISTERMINAL_H


#include "../Symbol.h"

enum TypeOfParenthesis {opening, closing};

class ParenthesisTerminal : public Symbol
{
private:
    TypeOfParenthesis typeOfParenthesis;

public:
    ParenthesisTerminal(const TypeOfParenthesis &typeOfParenthesis);

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    const TypeOfParenthesis & getTypeOfParenthesis() const
    {
        return typeOfParenthesis;
    }

    void setTypeOfParenthesis(const TypeOfParenthesis &typeOfParenthesis)
    {
        ParenthesisTerminal::typeOfParenthesis = typeOfParenthesis;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/

};


#endif //GL_PARENTHESISTERMINAL_H
