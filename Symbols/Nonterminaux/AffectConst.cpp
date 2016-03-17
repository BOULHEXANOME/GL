//
// Created by hdelval on 08/03/16.
//

#include "AffectConst.h"

std::string AffectConst::print() const
{
    return "const " + this->constToDeclare->print() + " = " + this->numberToAffect->print();
}
