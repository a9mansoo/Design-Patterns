#include "pizzastore.h"



PizzaStore::PizzaStore(PizzaFactory* p):pf{p}{}

PizzaStore::PizzaStore(){
    pf = new PizzaFactory();
}

PizzaStore::~PizzaStore(){
    if (pf != nullptr){
        delete pf;
    }
}


Pizza * PizzaStore::orderPizza(std::string& type){

    return pf->createPizza(type);

}
