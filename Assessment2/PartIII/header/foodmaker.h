#ifndef FOOD_MAKER_H
#define FOOD_MAKER_H

#include <vector>

class Manager;
class MenuItem;

class FoodMaker {
public:
    void makeFood(MenuItem* item);
    void setManager(Manager* mgr);
    void delStock(MenuItem* item);
    // void setData(vector<Food>* data);
    
private:
    Manager* manager;
    // vector<Food>* stock_data;
};

#endif  // FOOD_MAKER_H
