#ifndef E15_H
#define E15_H

#include "DefaultState.h"

class E15 : public DefaultState
{
protected:
	std::string expectedSymbols = "comma, ;";
	
public:
    E15();
    ~E15(){};
    // FIXME transition coma ??????
    virtual bool transitionComma(Automaton * automaton, Symbol * s);
    virtual bool transitionSemicolon(Automaton * automaton, Symbol * s);
};

#endif
