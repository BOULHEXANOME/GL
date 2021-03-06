//
// Created by hdelval on 08/03/16.
//

#include "AffectConst.h"

std::string AffectConst::print() const
{
    return "const " + this->constToDeclare->print() + " = " + this->numberToAffect->print();
}

int AffectConst::execute() const
{
    if(! Automaton::instance().declareAndAffectConst(this->constToDeclare->getTheName(), this->numberToAffect->getTheValue()))
    {
        Automaton::instance().printError(this);
    }
    return 0;
}

bool AffectConst::analyse()
{
    if(! Automaton::instance().analyseDeclareAndAffectConst(this->constToDeclare->getTheName()))
    {
        Automaton::instance().printError(this);
        return false;
    }
    return true;
}

bool AffectConst::optimize()
{
    execute();
    return true;
}
