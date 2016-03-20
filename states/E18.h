//
// Created by hdelval on 20/03/16.
//

#ifndef LUT_E18_H
#define LUT_E18_H


#include "DefaultState.h"

class E18 : public DefaultState
{
public:
    E18();
    ~E18(){};
    // FIXME transitions
    virtual bool transitionSemicolon(Automaton * automaton, Symbol * semicolon);

};


#endif //LUT_E18_H
