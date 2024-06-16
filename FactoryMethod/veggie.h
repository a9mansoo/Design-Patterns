#ifndef _VEGGIE_
#define _VEGGIE_
#include "pizza.h"
#include "string"
#include <iostream>


class VeggiePizza: public Pizza{
    private:
        std::string name;
    public:
        VeggiePizza();
        ~VeggiePizza();
        virtual void prepare() override;
        virtual void bake() override;
        virtual void serve() override;
};
#endif
