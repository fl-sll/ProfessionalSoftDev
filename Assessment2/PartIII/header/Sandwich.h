#ifndef SANDWICH_H
#define SANDWICH_H

#include "menuitem.h"
#include <string>

class Sandwich : public MenuItem
{
public:
    Sandwich(std::string name);
    std::string getName() const override;
    void chooseBread(std::string breadType);
    void chooseMeat(std::string meatType);
    void addCheese(int amount);
    void addVegetables(bool withVegetables);
    void chooseSauce(std::string sauceType);

protected:
    std::string name;
    std::string breadType;
    std::string meatType;
    int cheeseAmount;
    bool withVegetables;
    std::string sauceType;
};

class SubSandwich : public Sandwich
{
public:
    SubSandwich();
};

#endif
