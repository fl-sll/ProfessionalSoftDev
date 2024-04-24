#include "./../header1/sandwich.h"

Sandwich::Sandwich(std::string name) : name(name), breadType(""), meatType(""), cheeseAmount(0), withVegetables(false), sauceType("") {}

std::string Sandwich::getName() const
{
    return name;
}

void Sandwich::chooseBread(std::string breadType)
{
    this->breadType = breadType;
}

void Sandwich::chooseMeat(std::string meatType)
{
    this->meatType = meatType;
}

void Sandwich::addCheese(int amount)
{
    cheeseAmount = amount;
}

void Sandwich::addVegetables(bool withVegetables)
{
    this->withVegetables = withVegetables;
}

void Sandwich::chooseSauce(std::string sauceType)
{
    this->sauceType = sauceType;
}

SubSandwich::SubSandwich() : Sandwich("SubSandwich") {}
