#include "dropfirst.h"
#include <iostream>
#include <string>

Dropfirst::Dropfirst( TextProcessor * tp, int n ): Decorator{tp},num{n}{}

std::string Dropfirst::getWord(){
	std::string ret = tp->getWord();
	if ( ret.length() <= num){
		return getWord();
	}
		std::string curr = "";
		int i = 0;
		while ( i < ret.length()){
			if ( i >= num ){
			  curr = curr + ret[i];

			}
			i += 1;
		}
	
	return curr;
}

void Dropfirst::setSource(std::istream *in){ tp->setSource(in); }


