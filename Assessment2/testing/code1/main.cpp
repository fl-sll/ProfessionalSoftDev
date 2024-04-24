#include <iostream>
#include "./../header1/order.h"
#include "./../header1/patron.h"
#include "./../header1/manager.h"
#include "./../header1/foodmaker.h"
#include "./../header1/food.h"
#include "./../header1/coffeemaker.h"
#include "./../header1/host.h"


int main() {
    //// Create objects
    Host host;
    Manager manager;
    FoodMaker foodMaker;
    CoffeeMaker coffeeMaker;

    //// Set relationships between objects
    host.setManager(&manager);
    manager.setHost(&host);
    manager.setFoodMaker(&foodMaker);
    manager.setCoffeeMaker(&coffeeMaker);
    foodMaker.setManager(&manager);
    coffeeMaker.setManager(&manager);

    //// Patron enters the cafe
    Patron patron("Alice");

    //// Patron gives order to the host
    Order order;
    order.addItem(new Food("Candy Bar"));
    order.addItem(new Food("Chocolate Mousse"));
    order.addItem(new BlackCoffee());
    order.addItem(new WhiteCoffee());

    //// host take order from patron and forwards to manager
    host.takeOrder(&patron, &order);

    Patron patron1("John");

    //// Patron gives order to the host
    Order order1;
    order1.addItem(new Food("Candy Bar"));
    order1.addItem(new Food("Chocolate Mousse"));
    order1.addItem(new BlackCoffee());
    order1.addItem(new WhiteCoffee());

    //// host take order from patron and forwards to manager
    host.takeOrder(&patron1, &order1);

    return 0;
}
