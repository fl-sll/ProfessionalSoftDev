#include "./../header1/foodmaker.h"
#include "./../header1/manager.h"
#include <iostream>

void FoodMaker::makeFood(MenuItem* item) {
    std::cout << "Making food: " << item->getName() << std::endl;
    manager->foodReady();
}

void FoodMaker::setManager(Manager* mgr) {
    manager = mgr;
}
