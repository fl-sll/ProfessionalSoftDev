#ifndef COFFEE_H
#define COFFEE_H

#include "menuitem.h"

class Coffee : public MenuItem {
public:
    Coffee(std::string name);
    std::string getName() const override;
    void addSugar(int amount);
protected:
    std::string name;
    int sugars;
};

class BlackCoffee : public Coffee {
public:
    BlackCoffee();
};

class WhiteCoffee : public Coffee {
public:
    WhiteCoffee();
};

#endif  // COFFEE_H
