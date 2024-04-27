#include "./../header/coffee.h"
#include <sstream>

Coffee::Coffee(std::string name, int sugar) : name(name), sugars(sugar), stock(0) {}

std::string Coffee::getName() const
{
    return name;
}

int Coffee::getSugar() const{
    return sugars;
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

BlackCoffee::BlackCoffee() : Coffee("Black Coffee", 0) {}

WhiteCoffee::WhiteCoffee() : Coffee("White Coffee", 4) {}
