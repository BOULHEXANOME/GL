#include <iostream>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "Automaton.h"
#include "Lexer.h"

#define MIN_ARGS 2
#define MAX_ARGS 5

#define ERROR_NOT_ENOUGH_ARGS 1
#define ERROR_TOO_MANY_ARGS 1
#define ERROR_BAD_INPUT 1
#define ERROR_INCORRECT_PROGRAM 1

using namespace std;

void print_usage() {
  cerr << "  Utilisation :" << std::endl;
  cerr << "    ../lut [-p] [-a] [-e] [-o] source.lt" << endl;
  cerr << "      [-p] affiche le code source reconnu" << endl;
  cerr << "      [-a] analyse le programme de maniere statique" << endl;
  cerr << "      [-e] execute interactivement le programme" << endl;
  cerr << "      [-o] optimise les expressions et instructions" << endl;
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
    
    bool opt_print = false;
    bool opt_analyse = false;
	bool opt_execute = false; 
	bool opt_optimize = false;
	string file_path;
    
    if (argc < MIN_ARGS) {
		print_usage();
		exit(ERROR_NOT_ENOUGH_ARGS);
	}
    
	if (argc > MAX_ARGS) {
		print_usage();
		exit(ERROR_TOO_MANY_ARGS);
	}
	
	file_path = argv[argc-1];
    
    int opt,a,b,c;
    
    while ((opt = getopt(argc,argv,"paeo")) != EOF) {
        switch(opt)
        {
            case 'p': 
				cout << "Affichage du programme" << endl;
				opt_print = true;
				break;
            
            case 'a':
				cout << "Analyse statique du programme" << endl; 
				opt_analyse = true;
				break;
				
            
            case 'e':
				cout << "Execution du programme" << endl ; 
				opt_execute = true;
				break;
            
            case 'o':
				cout << "Simplification du programme " << endl ; 
				opt_optimize = true;
				break;
            
            case '?': print_usage();
				exit(ERROR_BAD_INPUT);
				break;
            
            default : 
				break;
        }
	}
  
	if(!file_exists(file_path)) {
		cerr << "Erreur a l'ouverture du fichier " << file_path << endl;
		exit(ERROR_BAD_INPUT);
	} else {
		
		// Instanciation du Lexer -> A changer de place possiblement
		Lexer lexer = new Lexer(file_path);
		
		// Parcourt le fichier et ajoute les symboles à la pile
		do {
			Symbol symbol = lexer.getSymbol();
			
			// Ajouter le symbole à la pile des symboles
			//symbolsStack.push(symbol);

		} while(symbol->getType() != SymbolType::END);
		
	}

	if(opt_analyse) {

	}

	if(opt_optimize) {

	}

	if(opt_print) {

	}

	if(opt_execute) {

	}


    //Automaton::instance().createAndDeleteSomeLines();
    return 0;
}

