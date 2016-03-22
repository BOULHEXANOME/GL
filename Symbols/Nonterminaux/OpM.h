#ifndef OpM_H
#define OpM_H


#include "../Symbol.h"

class OpM : public Symbol
{
public:
		virtual int execute() const;
		int getOp();
		void setOp(int i);
		
private:
		int op;
};


#endif
