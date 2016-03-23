//
// Created by hdelval on 04/03/16.
//

#include "Read.h"

std::string Read::print() const
{
    return "lire " + variableToReadFromUser->print();
}

int Read::execute() const
{
    int numberFromUser;
    std::cout << variableToReadFromUser->getTheName() << " = ?" << std::endl;
    std::cin >> numberFromUser;
    if(! Automaton::instance().affectVariable(this->variableToReadFromUser->getTheName(), numberFromUser))
    {
        Automaton::instance().printError(this);
    }
    return 0;
}

bool Read::analyse() const
{
    if(! Automaton::instance().analyseAffectVariable(this->variableToReadFromUser->getTheName()))
    {
        Automaton::instance().printError(this);
        return false;
    }
    return true;
}
