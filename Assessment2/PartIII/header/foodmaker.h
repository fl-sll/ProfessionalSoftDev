#ifndef FOOD_MAKER_H
#define FOOD_MAKER_H

#include <vector>
#include "food.h"

class Manager;
class MenuItem;

class FoodMaker
{
public:
    FoodMaker(std::vector<Food> food);
    void makeFood(MenuItem *item);
    void setManager(Manager *mgr);
    void delStock(std::string name);
    // void setData(vector<Food>* data);

private:
    Manager *manager;
    std::vector<Food> food;
};

#endif // FOOD_MAKER_H
