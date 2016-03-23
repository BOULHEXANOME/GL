//
// Created by hdelval on 20/03/16.
//

#ifndef LUT_E37_H
#define LUT_E37_H


#include "DefaultState.h"

class E37 : public DefaultState
{
public:
    E37();
    ~E37(){};
   
    virtual bool transitionCloseParenthesis(Automaton * automaton, Symbol * closeParenthesis);
};


#endif //LUT_E37_H
