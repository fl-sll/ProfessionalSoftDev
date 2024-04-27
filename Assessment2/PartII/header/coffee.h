#ifndef COFFEE_H
#define COFFEE_H

#include "menuitem.h"

class Coffee : public MenuItem
{
public:
    Coffee(std::string name, int sugar);
    std::string getName() const override;
    int getSugar() const;
    void addSugar(int amount);
    std::string getDetails();
    void addStock(int amount);

protected:
    std::string name;
    int sugars;
    int stock;
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
