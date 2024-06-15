#ifndef __DROPFIRST_H__
#define __DROPFIRST_H__
#include <iostream>
#include <string>
#include "decorator.h"
#include "textprocess.h"


class Dropfirst: public Decorator{
	int num;
public:
	Dropfirst( TextProcessor * tp, int n);
	std::string getWord() override;
	void setSource(std::istream *in) override;


};
#endif



