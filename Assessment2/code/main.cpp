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

    bool Active = true;
    while (Active)
    {
        readMenu();
        string name;
        cout << "Patron name: ";
        cin >> name;

        //// Patron enters the cafe
        Patron patron(name);

        cout << "Hi " << patron.getName() << "! Welcome to SAJA Café";
        cout << "> What do you want to order?" << endl;


        //// Patron gives order to the host
        Order order;
        order.addItem(new Food("Candy Bar"));
        order.addItem(new Food("Chocolate Mousse"));
        order.addItem(new BlackCoffee());
        order.addItem(new WhiteCoffee());

        //// host take order from patron and forwards to manager
        host.takeOrder(&patron, &order);
    }

    return 0;
}
