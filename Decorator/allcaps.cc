#include "allcaps.h"
#include <iostream>
#include <string>

Allcaps::Allcaps( TextProcessor * tp ): Decorator{tp}{}

std::string Allcaps::getWord(){
	std::string ret = tp->getWord();
	int offset = 'a' - 'A';
	for (int i = 0; i < ret.length(); ++i ){
		if ( ret[i] >= 'a' && ret[i] <= 'z'){
			ret[i] = ret[i] - offset;
		}
	}
	return ret;
}

void Allcaps::setSource(std::istream *in){ tp->setSource(in); }


