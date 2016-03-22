#include "OpA.h"

int OpA::execute() const
{
	
    std::cerr <<"Error, cannot execute Expression."<<std::endl;
	return 0;
}

int OpA::getOp(){
	return op;
}

void OpA::setOp(int i){
	op = i;
}
