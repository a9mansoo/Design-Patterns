#ifndef _CLAM_
#define _CLAM_
#include "pizza.h"
#include "string"
#include <iostream>


class ClamPizza: public Pizza{
    private:
        std::string name;
    public:
        ClamPizza();
        ~ClamPizza();
        virtual void prepare() override;
        virtual void bake() override;
        virtual void serve() override;
};
#endif