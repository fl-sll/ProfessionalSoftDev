#include "./../header/coffee.h"
#include <sstream>

Coffee::Coffee(std::string name) : name(name), sugars(0), stock(0) {}

std::string Coffee::getName() const
{
    return name;
}

void Coffee::addSugar(int amount)
{
    sugars += amount;
}
void Coffee::addStock(int amount)
{
    stock += amount;
}

std::string Coffee::getDetails()
{
    std::stringstream ss;
    ss << name << " has " << sugars << " sugar. Stock = " << stock;
    return ss.str();
}

BlackCoffee::BlackCoffee() : Coffee("Black Coffee") {}

WhiteCoffee::WhiteCoffee() : Coffee("White Coffee") {}
