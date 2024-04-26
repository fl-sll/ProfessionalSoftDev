#ifndef COFFEE_MAKER_H
#define COFFEE_MAKER_H

#include <vector>

class MenuItem;
class Manager;

class CoffeeMaker {
public:
    void makeCoffee(MenuItem* item);
    void setManager(Manager* mgr);
    void delStock(MenuItem* item);
    void setData(<vector<Coffee>>* data);
private:
    Manager* manager;
    <vector<Drink>>* stock_data;
};

#endif  // COFFEE_MAKER_H
