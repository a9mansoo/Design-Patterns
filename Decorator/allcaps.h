#ifndef __ALLCAPS_H__
#define __ALLCAPS_H__
#include <iostream>
#include <string>
#include "decorator.h"
#include "textprocess.h"


class Allcaps: public Decorator {
public:
	Allcaps( TextProcessor * tp);
	std::string getWord() override;
	void setSource(std::istream *) override;

};
#endif


