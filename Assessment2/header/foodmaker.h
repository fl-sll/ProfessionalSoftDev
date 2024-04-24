#ifndef FOOD_MAKER_H
#define FOOD_MAKER_H

class Manager;
class MenuItem;

class FoodMaker {
public:
    void makeFood(MenuItem* item);
    void setManager(Manager* mgr);
private:
    Manager* manager;
};

#endif  // FOOD_MAKER_H
