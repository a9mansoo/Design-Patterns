#include "clam.h"



ClamPizza::ClamPizza():name{"Clam"}{

}

ClamPizza::~ClamPizza(){

}


void ClamPizza::prepare(){
    std::cout << "Preparing Clam Pizza" << std::endl;

}


void ClamPizza::bake(){
    std::cout << "Baking Clam Pizza" << std::endl;
}


void ClamPizza::serve(){
    std::cout << "Serving Clam Pizza" << std::endl;
}
