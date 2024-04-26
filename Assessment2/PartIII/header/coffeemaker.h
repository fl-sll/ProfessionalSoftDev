#ifndef COFFEE_MAKER_H
#define COFFEE_MAKER_H

#include <vector>
#include "coffee.h"

class MenuItem;
class Manager;

class CoffeeMaker {
public:
    CoffeeMaker(std::vector<Coffee> drinks);
    void makeCoffee(MenuItem* item);
    void setManager(Manager* mgr);
    void delStock(std::string name);
    // void setVector(std::vector<Coffee>* vector);
    // void setData(<vector<Coffee>>* data);
private:
    Manager* manager;
    std::vector<Coffee> drinks;
};

#endif  // COFFEE_MAKER_H
