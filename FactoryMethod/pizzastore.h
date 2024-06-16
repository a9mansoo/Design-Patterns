#ifndef _STORE_
#define _STORE_
#include "simplepizzafactory.h"
#include "pizza.h"


class PizzaStore{
    private:
        PizzaFactory * pf;
    
    public:
        PizzaStore();
        PizzaStore(PizzaFactory * p);
        ~PizzaStore();
        Pizza * orderPizza(std::string& type);


};
#endif
