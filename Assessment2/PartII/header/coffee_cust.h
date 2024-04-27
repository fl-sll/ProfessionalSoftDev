#ifndef COFFEE_H
#define COFFEE_H

#include "menuitem.h"
#include <string>

class Coffee : public MenuItem
{
public:
    Coffee(std::string name);
    std::string getName() const override;
    void addSugar(int amount);
    void addEspressoShot(int amount);
    void addVanillaSyrup();
    void addHazelnutSyrup();
    void setMilk(std::string milkType);
    void setTemperature(bool hot); // true for hot, false for cold
protected:
    std::string name;
    int sugars;
    int espressoShots;
    bool hasVanillaSyrup;
    bool hasHazelnutSyrup;
    std::string milkType;
    bool isHot;
};

class BlackCoffee : public Coffee
{
public:
    BlackCoffee();
};

class WhiteCoffee : public Coffee
{
public:
    WhiteCoffee();
};

#endif // COFFEE_H
