#include "./../header1/coffeemaker.h"
#include "./../header1/manager.h"
#include <iostream>

void CoffeeMaker::makeCoffee(MenuItem* item) {
    std::cout << "Making coffee: " << item->getName() << std::endl;
    manager->coffeeReady();
}

void CoffeeMaker::setManager(Manager* mgr) {
    manager = mgr;
}
