#include "pizzastore.h"
#include "pizza.h"
#include <iostream>
#include <string>

int main(){

    PizzaStore * pizzastore = new PizzaStore();
    std::string command;
    while ( true ){
        std::cout << "Enter an order" << std::endl;
        std::getline(std::cin, command);
        if ( std::cin.fail() || command == "quit" ) break;
        Pizza * pizza = pizzastore->orderPizza(command);
        
        if (pizza != nullptr){
            pizza->prepare();
            pizza->bake();
            pizza->serve();
            delete pizza;
        }
    }
    if (pizzastore != nullptr){
        delete pizzastore;
    }

    return 0;
};





