#include "count.h"
#include <iostream>
#include <string>
#include <sstream>
Count::Count( TextProcessor * tp, char c): Decorator{tp},c{c},counter{1}{}

std::string Count::getWord(){
	std::string ret = tp->getWord();
	std::string val = "";
	for (int i = 0; i < ret.length(); ++i){
		if (ret[i] == c){
			std::stringstream ss;
			ss << counter;
			std::string num = "";
			ss >> num;
			val = val + num;
			counter += 1;

		}
		else{
			val = val + ret[i];

		}

	}
	return val;
}

void Count::setSource(std::istream *in) { tp->setSource(in); }


