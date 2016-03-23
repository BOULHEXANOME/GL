//
// Created by hdelval on 22/03/16.
//

#ifndef LUT_E7_H
#define LUT_E7_H


#include "DefaultState.h"

class E7 : public DefaultState
{
protected:
	std::string expectedSymbols = "id, one or many affectations";
	
public:
    E7();
    virtual bool transitionId(Automaton * automaton, Symbol * id);
    virtual bool transitionAff(Automaton * automaton, Symbol * aff);
};


#endif //LUT_E7_H
