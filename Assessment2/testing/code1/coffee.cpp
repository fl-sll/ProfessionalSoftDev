#include "./../header1/coffee.h"

Coffee::Coffee(std::string name) : name(name), sugars(0) {}

std::string Coffee::getName() const {
    return name;
}

void Coffee::addSugar(int amount) {
    sugars += amount;
}

BlackCoffee::BlackCoffee() : Coffee("Black Coffee") {}

WhiteCoffee::WhiteCoffee() : Coffee("White Coffee") {}
