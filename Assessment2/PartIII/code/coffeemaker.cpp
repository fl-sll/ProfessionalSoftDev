#include "./../header/coffeemaker.h"
#include "./../header/manager.h"
#include "./../header/coffee.h"
#include "./../header/readJson.h"
#include <iostream>
#include <windows.h>
#include <vector>

CoffeeMaker::CoffeeMaker(std::vector<Coffee> drinks) : drinks(drinks) {}

void CoffeeMaker::makeCoffee(MenuItem* item) {
    std::cout << "Making coffee: " << item->getName() << std::endl;
    // item->delStock();
    std::cout << item->getStock() << std::endl;
    this->delStock(item->getName());
    Sleep(1000);
    manager->coffeeReady();
};

void CoffeeMaker::setManager(Manager* mgr) {
    manager = mgr;
}

// void CoffeeMaker::setVector(std::vector<Coffee>* vector) {
//     this->drinks = vector;
// }

void CoffeeMaker::delStock(std::string name) {
    // std::cout << "debug======="<< std::endl<< name<< std::endl;
    // std::cout << "debug======="<< std::endl<< drinks[name].getStock()<< std::endl;
    updateJsonDrink(drinks, name);
}