#ifndef COFFEE_MAKER_H
#define COFFEE_MAKER_H

class MenuItem;
class Manager;

class CoffeeMaker {
public:
    void makeCoffee(MenuItem* item);
    void setManager(Manager* mgr);
private:
    Manager* manager;
};

#endif  // COFFEE_MAKER_H
