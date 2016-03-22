#ifndef OpA_H
#define OpA_H


#include "../Symbol.h"

class OpA : public Symbol
{
public:
		virtual int execute() const;
		int getOp();
		void setOp(int i);
		
private:
		int op;
};


#endif
