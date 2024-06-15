#ifndef __COUNT_H_
#define __COUNT_H_
#include <iostream>
#include <string>
#include "decorator.h"
#include "textprocess.h"


class Count: public Decorator{
	char c;
	int counter;
public:
	Count( TextProcessor * tp, char c);
	std::string getWord() override;
	void setSource(std::istream *in) override;
};
#endif

