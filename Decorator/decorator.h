#ifndef __DECORATOR_H__
#define __DECORATOR_H__
#include <iostream>
#include <string>
#include "textprocess.h"

// Abstract Base class for Decorator

class Decorator: public TextProcessor{
protected:
	TextProcessor * tp; // TextProcessor object pointer
public:
	Decorator( TextProcessor * ); // Initializes decorator pointer to TextProcessor object
	~Decorator(); // Destructor
	virtual std::string getWord()=0; // pure virtual
	virtual void setSource(std::istream *in)=0; // pure virtual
};
#endif

