#ifndef _CHEESE_
#define _CHEESE_
#include "pizza.h"
#include "string"
#include <iostream>


class CheesePizza: public Pizza{
    private:
        std::string name;
    public:
        CheesePizza();
        ~CheesePizza();
        virtual void prepare() override;
        virtual void bake() override;
        virtual void serve() override;
};
#endif
