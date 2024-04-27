#ifndef FOOD_H
#define FOOD_H

#include "menuitem.h"

class Food : public MenuItem {
public:
    Food(std::string name);
    std::string getName() const override;
    void addStock(int amount);
    std::string getDetails();
private:
    std::string name;
    int stock;
};

#endif  // FOOD_H
