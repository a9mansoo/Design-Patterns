#ifndef _FACTORY_
#define _FACTORY_
#include "string"
#include "pizza.h"
#include "cheese.h"
#include "veggie.h"
#include "clam.h"


class PizzaFactory{
    public:
        PizzaFactory();
        ~PizzaFactory();
        Pizza * createPizza(std::string& name);

};
#endif
