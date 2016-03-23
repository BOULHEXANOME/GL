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
        // TODO
        std::cerr << "error declare const ! print line number&column" << std::endl;
    }
    return 0;
}

bool AffectConst::analyse() const
{
    if(! Automaton::instance().analyseDeclareAndAffectConst(this->constToDeclare->getTheName()))
    {
        // TODO
        std::cerr << "error declare const ! print line number&column" << std::endl;
        return false;
    }
    return true;
}
