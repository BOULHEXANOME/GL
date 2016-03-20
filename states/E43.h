//
// Created by hdelval on 20/03/16.
//

#ifndef LUT_E43_H
#define LUT_E43_H


#include "DefaultState.h"

class E43 : public DefaultState
{
public:
    E43();
    ~E43(){};
    virtual bool transitionDollar(Automaton * automaton, Symbol * dollar);
};


#endif //LUT_E43_H
