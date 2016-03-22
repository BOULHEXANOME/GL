#include "OpM.h"

int OpM::execute() const
{
	
    std::cerr <<"Error, cannot execute OpM."<<std::endl;
	return 0;
}

int OpM::getOp(){
	return op;
}

void OpM::setOp(int i){
	op = i;
}
