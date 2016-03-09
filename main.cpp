#include <iostream>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
//#include "Automaton.h"

#define MIN_ARGS 2
#define MAX_ARGS 5

#define ERROR_NOT_ENOUGH_ARGS 1
#define ERROR_TOO_MANY_ARGS 1
#define ERROR_BAD_INPUT 1
#define ERROR_INCORRECT_PROGRAM 1

using namespace std;

void print_usage() {
  cerr << "  Utilisation :" << std::endl;
  cerr << "    ../lut [-p] [-a] [-e] [-o] source.lt" << std::endl;
  cerr << "      [-p] affiche le code source reconnu" << std::endl;
  cerr << "      [-a] analyse le programme de maniere statique" << std::endl;
  cerr << "      [-e] execute interactivement le programme" << std::endl;
  cerr << "      [-o] optimise les expressions et instructions" << std::endl;
}

inline bool file_exists (const string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

int main(int argc, char **argv) {
    
    if (argc < MIN_ARGS) {
		print_usage();
		exit(ERROR_NOT_ENOUGH_ARGS);
	}
    
	if (argc > MAX_ARGS) {
		print_usage();
		exit(ERROR_TOO_MANY_ARGS);
	}
    
    int opt,a,b,c;
    while ((opt = getopt(argc,argv,"paeo")) != EOF)
        switch(opt)
        {
            case 'p': 
				cout << "Affichage du programme" << endl; 
				break;
            
            case 'a':
				cout << "Analyse statique du programme" << endl; 
				break;
            
            case 'e':
				cout << "Execution du programme" << endl ; 
				break;
            
            case 'o':
				cout << "Simplification du programme " << endl ; 
				break;
            
            case '?': print_usage();
				exit(ERROR_BAD_INPUT);
				break;
            
            default: cout<< "Analyse du fichier" << endl;
        }

    //Automaton::instance().createAndDeleteSomeLines();
    return 0;
}

