//
// Created by hsipahimal on 09/03/16.
//

#ifndef GL_SYMBOLTYPES_H
#define GL_SYMBOLTYPES_H

//Terminaux
const int NON_TERMINAL = 0;
const int PLUS = 1;
const int MINUS = 2;
const int MULTIPLY = 3;
const int DIVIDE = 4;
const int WRITE = 5;
const int READ = 6;
const int AFFECTDECLARE = 7;
const int AFFECTINSTRUCT = 8;
const int OPENPARENTHESIS = 9;
const int CLOSEPARENTHESIS = 10;
const int VAR = 11;
const int VAL = 12;
const int DOLLAR = 13;
const int CONST = 14;
const int COMMA = 15;
const int SEMICOLON = 16;
const int ID = 17;
const int ERROR = 18;

//Non terminaux
const int P = 19;
const int D = 20;
const int D_PRIME = 21;
const int ID_LISTE = 22;
const int AFF = 23;
const int I = 24;
const int I_PRIME = 25;
const int E = 26;
const int T = 27;
const int F = 28;
const int OPA = 29;
const int OPM = 30;
const int NUMBER = 31;


#endif //GL_SYMBOLTYPES_H
