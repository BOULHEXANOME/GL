#ifndef E15_H
#define E15_H

#include "DefaultState.h"

class E15 : public DefaultState
{
public:
    E15();
    virtual bool transitionComma(Automaton * automaton, Symbol * s);
    virtual bool transitionSemicolon(Automaton * automaton, Symbol * s);
};

#endif
