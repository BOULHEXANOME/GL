#include <iostream>
#include "Automaton.h"
#include "Lexer.h"

#include "regex"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    Lexer lex("Bonjour");
    lex.getSymbol();
    //Automaton::instance().createAndDeleteSomeLines();

    return 0;
}
