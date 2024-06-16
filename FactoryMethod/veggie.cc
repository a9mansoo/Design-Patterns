#include "veggie.h"



VeggiePizza::VeggiePizza():name{"Veggie"}{

}

VeggiePizza::~VeggiePizza(){

}


void VeggiePizza::prepare(){
    std::cout << "Preparing Veggie Pizza" << std::endl;

}


void VeggiePizza::bake(){
    std::cout << "Baking Veggie Pizza" << std::endl;
}


void VeggiePizza::serve(){
    std::cout << "Serving Veggie Pizza" << std::endl;
}
