#include "./../header/coffeemaker.h"
#include "./../header/manager.h"
#include <iostream>

void CoffeeMaker::makeCoffee(MenuItem* item) {
    std::cout << "Making coffee: " << item->getName() << std::endl;
    manager->coffeeReady();
};

void CoffeeMaker::setManager(Manager* mgr) {
    manager = mgr;
}
