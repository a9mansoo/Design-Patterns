#include "cheese.h"



CheesePizza::CheesePizza():name{"cheese"}{

}

CheesePizza::~CheesePizza(){

}


void CheesePizza::prepare(){
    std::cout << "Preparing Cheese Pizza" << std::endl;

}


void CheesePizza::bake(){
    std::cout << "Baking Cheese Pizza" << std::endl;
}


void CheesePizza::serve(){
    std::cout << "Serving Cheese Pizza" << std::endl;
}
