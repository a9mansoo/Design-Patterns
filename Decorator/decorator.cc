#include "decorator.h"
#include <iostream>
#include <string>

Decorator::Decorator( TextProcessor * curr_tp): tp{curr_tp}{}

Decorator::~Decorator(){
	delete tp;
}


