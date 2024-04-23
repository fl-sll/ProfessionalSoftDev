#include <iostream>
#include "./../header1/order.h"
#include "./../header1/patron.h"
#include "./../header1/manager.h"
#include "./../header1/foodmaker.h"
#include "./../header1/food.h"
#include "./../header1/coffeemaker.h"
#include "./../header1/host.h"

int main() {
    // Create objects
    Host host;
    Manager manager;
    FoodMaker foodMaker;
    CoffeeMaker coffeeMaker;

    // Set relationships between objects
    host.setManager(&manager);
    manager.setHost(&host);
    manager.setFoodMaker(&foodMaker);
    manager.setCoffeeMaker(&coffeeMaker);
    foodMaker.setManager(&manager);
    coffeeMaker.setManager(&manager);

    // Patron enters the cafe
    Patron patron("Alice");

    // Patron gives order to the host
    Order order;
    order.addItem(new Food("Candy Bar"));
    host.takeOrder(&patron, &order);

    return 0;
}
