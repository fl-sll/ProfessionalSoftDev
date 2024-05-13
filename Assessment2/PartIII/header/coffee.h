#ifndef COFFEE_H
#define COFFEE_H

#include "menuitem.h"

class Coffee : public MenuItem
{
public:
    Coffee(std::string name, float sugar, int stock);
    std::string getName() const override;
    int getStock() const override;
    // void delStock();
    float getSugar() const;
    void addSugar(float amount);
    std::string getDetails();
    void addStock(int amount);

protected:
    std::string name;
    int sugars;
    int stock;
};

#endif // COFFEE_H
