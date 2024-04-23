#ifndef FOOD_H
#define FOOD_H

#include "menuitem.h"

class Food : public MenuItem {
public:
    Food(std::string name);
    std::string getName() const override;
private:
    std::string name;
};

#endif  // FOOD_H
