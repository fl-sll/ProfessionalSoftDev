#ifndef COFFEE_H
#define COFFEE_H

#include "menuitem.h"

class Coffee : public MenuItem
{
public:
    Coffee(std::string name, int sugar, int stock);
    std::string getName() const override;
    int getStock() const override;
    // void delStock();
    int getSugar() const;
    void addSugar(int amount);
    std::string getDetails();
    void addStock(int amount);

protected:
    std::string name;
    int sugars;
    int stock;
};

#endif // COFFEE_H
