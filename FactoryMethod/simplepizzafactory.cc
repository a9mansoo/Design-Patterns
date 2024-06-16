#include "simplepizzafactory.h"



PizzaFactory::PizzaFactory(){

}

PizzaFactory::~PizzaFactory(){

}


Pizza * PizzaFactory::createPizza(std::string& name){
    Pizza * p = nullptr;
    if (name == "cheese"){
        p = new CheesePizza();
    }
    else if (name == "clam"){
        p = new ClamPizza();

    }
    else if (name == "veggie"){
        p = new VeggiePizza();
    }

    return p;
}
