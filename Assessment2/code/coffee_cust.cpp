#include "./../header/coffee_cust.h"

Coffee::Coffee(std::string name) : name(name), sugars(0), espressoShots(0), hasVanillaSyrup(false), hasHazelnutSyrup(false), milkType("Regular"), isHot(true) {}

std::string Coffee::getName() const
{
    return name;
}

void Coffee::addSugar(int amount)
{
    sugars += amount;
}

void Coffee::addEspressoShot(int amount)
{
    espressoShots += amount;
}

void Coffee::addVanillaSyrup()
{
    hasVanillaSyrup = true;
}

void Coffee::addHazelnutSyrup()
{
    hasHazelnutSyrup = true;
}

void Coffee::setMilk(std::string milkType)
{
    this->milkType = milkType;
}

void Coffee::setTemperature(bool hot)
{
    isHot = hot;
}

BlackCoffee::BlackCoffee() : Coffee("Black Coffee") {}

WhiteCoffee::WhiteCoffee() : Coffee("White Coffee") {}
