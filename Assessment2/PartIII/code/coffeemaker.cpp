#include "./../header/coffeemaker.h"
#include "./../header/manager.h"
#include "./../header/coffee.h"
#include <iostream>
#include <windows.h>


void CoffeeMaker::makeCoffee(MenuItem* item) {
    std::cout << "Making coffee: " << item->getName() << std::endl;
    // item->delStock();
    this->delStock(item);
    Sleep(1000);
    manager->coffeeReady();
};

void CoffeeMaker::setManager(Manager* mgr) {
    manager = mgr;
}

void CoffeeMaker::delStock(MenuItem* item) {
    std::cout << stock_data;
}

void CoffeeMaker::setData(<vector<Drink>>* data){
    stock_data = data;
};