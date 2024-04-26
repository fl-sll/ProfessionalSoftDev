#ifndef FOOD_H
#define FOOD_H

#include "menuitem.h"

class Food : public MenuItem {
public:
    Food(std::string name, int stock);
    std::string getName() const override;
    int getStock() const override;
    void addStock(int amount);
    std::string getDetails();
    void delStock();
private:
    std::string name;
    int stock;
};

#endif  // FOOD_H
