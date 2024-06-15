#ifndef __DOUBLEWORDS_H__
#define __DOUBLEWORDS_H__
#include <iostream>
#include <string>
#include "decorator.h"
#include "textprocess.h"


class Doublewords: public Decorator{
static int call;
static std::string curr_word;

public:
	Doublewords( TextProcessor * tp);
	std::string getWord() override;
	void setSource(std::istream *in) override;


};
#endif


