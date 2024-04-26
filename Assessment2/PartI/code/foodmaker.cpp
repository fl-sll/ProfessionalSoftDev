#include "./../header/foodmaker.h"
#include "./../header/manager.h"
#include <iostream>
#include <windows.h>

void FoodMaker::makeFood(MenuItem* item) {
    std::cout << "Making food: " << item->getName() << std::endl;
    Sleep(1000);
    manager->foodReady();
};

void FoodMaker::setManager(Manager* mgr) {
    manager = mgr;
}
