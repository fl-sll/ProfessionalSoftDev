#include <iostream>
#include "./../header/order.h"
#include "./../header/patron.h"
#include "./../header/manager.h"
#include "./../header/foodmaker.h"
#include "./../header/food.h"
#include "./../header/coffeemaker.h"
#include "./../header/host.h"
// #include "./../header/sandwich.h" 


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

    //// Patron 1 enters the cafe
    Patron patron("Alice");

    //// Patron gives order to the host
    Order order;
    order.addItem(new Food("Candy Bar"));
    order.addItem(new Food("Chocolate Mousse"));
    order.addItem(new BlackCoffee());
    order.addItem(new WhiteCoffee());

    //// host take order from patron and forwards to manager
    host.takeOrder(&patron, &order);

    Patron patron1("John"); // Patron 2 enters cafe

    //// Patron gives order to the host
    Order order1;
    order1.addItem(new Food("Candy Bar"));
    order1.addItem(new Food("Chocolate Mousse"));
    order1.addItem(new BlackCoffee());
    order1.addItem(new WhiteCoffee());

    //// host take order from patron and forwards to manager
    // host.takeOrder(&patron2, &order2);

    // Patron patron2("Josh pecinta onigiri");

    //// Patron gives order to the host
    // Order order2;
    // order2.addItem(new Food("Candy Bar"));
    // order2.addItem(new BlackCoffee());
    // order2.addItem(new SubSandwich()); // Add a SubSandwich to the order

    //// Host takes order from patron and forwards to manager
    // host.takeOrder(&patron2, &order2);

    return 0;
}
