#include "./../header/foodmaker.h"
#include "./../header/manager.h"
#include <iostream>
#include <windows.h>

void FoodMaker::makeFood(MenuItem* item) {
    std::cout << "Making food: " << item->getName() << std::endl;
    Sleep(1000);
    // item->delStock();
    this->delStock(item);    
    manager->foodReady();
};

void FoodMaker::setManager(Manager* mgr) {
    manager = mgr;
}
void FoodMaker::delStock(MenuItem* item) {
    std::cout << stock_data;
}

void FoodMaker::setData(<vector<Food>>* data){
};