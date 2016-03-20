//
// Created by hdelval on 20/03/16.
//

#ifndef LUT_E4_H
#define LUT_E4_H


#include "DefaultState.h"

class E4 : public DefaultState
{
public:
    E4();
    ~E4(){};
    virtual bool transitionSemicolon(Automaton * a, Symbol * s);

};


#endif //LUT_E4_H
