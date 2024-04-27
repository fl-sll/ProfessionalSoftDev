#include "./../header/coffeemaker.h"
#include "./../header/manager.h"
#include <iostream>
#include <windows.h>

void CoffeeMaker::makeCoffee(MenuItem* item) {
    std::cout << "Making coffee: " << item->getName() << std::endl;
    Sleep(1000);
    manager->coffeeReady();
};

void CoffeeMaker::setManager(Manager* mgr) {
    manager = mgr;
}
