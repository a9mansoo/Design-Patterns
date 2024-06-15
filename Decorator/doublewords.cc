#include "doublewords.h"
#include <iostream>
#include <string>


Doublewords::Doublewords( TextProcessor * tp): Decorator{tp}{}

std::string Doublewords::getWord(){
	if ( call == 0 ){
		std::string ret = tp->getWord();
		call = 1;
		curr_word = ret;
		return ret;
	}
	else{
		call = 0;
		return curr_word;
	}
}

void Doublewords::setSource(std::istream * in) { tp->setSource(in); }

int Doublewords::call = 0;
std::string Doublewords::curr_word = "";


