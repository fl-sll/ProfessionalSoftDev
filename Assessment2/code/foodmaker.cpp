#include "./../header/foodmaker.h"
#include "./../header/manager.h"
#include <iostream>

void FoodMaker::makeFood(MenuItem* item) {
    std::cout << "Making food: " << item->getName() << std::endl;
    manager->foodReady();
}

void FoodMaker::setManager(Manager* mgr) {
    manager = mgr;
}
