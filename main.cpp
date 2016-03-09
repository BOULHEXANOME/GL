#include <iostream>
#include "Automaton.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    Automaton::instance().createAndDeleteSomeLines();
    return 0;
}
