#include "./../header/manager.h"
// #include <windows.h>

#include <iostream>

void Manager::receiveOrder(Patron* patron, Order* order) {
    for (auto item : order->getItems()) {
        if (dynamic_cast<Food*>(item)) {
            foodMaker->makeFood(item);
            // Sleep(1000);
        } else if (dynamic_cast<Coffee*>(item)) {
            coffeeMaker->makeCoffee(item);
            // Sleep(1000);
        }
    }
    host->notifyPatron(patron->getName(), order);
}

void Manager::setFoodMaker(FoodMaker* maker) {
    foodMaker = maker;
}

void Manager::setCoffeeMaker(CoffeeMaker* maker) {
    coffeeMaker = maker;
}

void Manager::setHost(Host* hst) {
    host = hst;
}

void Manager::coffeeReady() {
    std::cout << "Coffee is ready!" << std::endl;
}

void Manager::foodReady() {
    std::cout << "Food is ready!" << std::endl;
}
