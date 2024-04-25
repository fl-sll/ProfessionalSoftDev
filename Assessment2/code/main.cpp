#include <iostream>
#include "./../header/order.h"
#include "./../header/patron.h"
#include "./../header/manager.h"
#include "./../header/foodmaker.h"
#include "./../header/food.h"
#include "./../header/coffeemaker.h"
#include "./../header/host.h"
// #include "./../header/sandwich.h" 

using namespace std;

int main()
{
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

<<<<<<< Updated upstream
    //// Patron 1 enters the cafe
    Patron patron("Alice");
=======
    bool Active = true;
    while (Active)
    {
        readMenu();
        string name;
        cout << "Patron name: ";
        cin >> name;
>>>>>>> Stashed changes

        //// Patron enters the cafe
        Patron patron(name);

        cout << "Hi " << patron.getName() << "! Welcome to SAJA Café";
        cout << "> What do you want to order?" << endl;

<<<<<<< Updated upstream
    Patron patron1("John"); // Patron 2 enters cafe
=======
>>>>>>> Stashed changes

        //// Patron gives order to the host
        Order order;
        order.addItem(new Food("Candy Bar"));
        order.addItem(new Food("Chocolate Mousse"));
        order.addItem(new BlackCoffee());
        order.addItem(new WhiteCoffee());

<<<<<<< Updated upstream
    //// host take order from patron and forwards to manager
    // host.takeOrder(&patron2, &order2);

    // Patron patron2("Josh pecinta onigiri");

    //// Patron gives order to the host
    // Order order2;
    // order2.addItem(new Food("Candy Bar"));
    // order2.addItem(new BlackCoffee());

    // SubSandwich* subSandwich = new SubSandwich();
    // subSandwich->chooseBread("Wheat");
    // subSandwich->chooseMeat("Turkey");
    // subSandwich->addCheese(2);
    // subSandwich->addVegetables(true);
    // subSandwich->chooseSauce("Mayonnaise");
    // order2.addItem(new SubSandwich()); // Add a SubSandwich to the order

    //// Host takes order from patron and forwards to manager
    // host.takeOrder(&patron2, &order2);
=======
        //// host take order from patron and forwards to manager
        host.takeOrder(&patron, &order);
    }
>>>>>>> Stashed changes

    return 0;
}
