#include <iostream>
#include <vector>
#include "./../header/order.h"
#include "./../header/patron.h"
#include "./../header/manager.h"
#include "./../header/foodmaker.h"
#include "./../header/food.h"
#include "./../header/coffeemaker.h"
#include "./../header/host.h"
#include "./../header/readJson.h"
// #include "./../header/sandwich.h"

using namespace std;

int main()
{
    //// Create objects
    // Host host;
    // Manager manager;
    // FoodMaker foodMaker;
    // CoffeeMaker coffeeMaker;

    //// Set relationships between objects
    // host.setManager(&manager);
    // manager.setHost(&host);
    // manager.setFoodMaker(&foodMaker);
    // manager.setCoffeeMaker(&coffeeMaker);
    // foodMaker.setManager(&manager);
    // coffeeMaker.setManager(&manager);

<<<<<<< Updated upstream
=======
    // repeat for next customer, end to close shift
>>>>>>> Stashed changes
    bool Active = true;
    while (Active)
    {
        // readMenu();

        pair<vector<Coffee>, vector<Food> > r = readMenu();
        vector<Coffee> drinkvector = r.first;
        vector<Food> foodvector = r.second;

        // for (int i = 0; i < foodvector.size(); ++i)
        // {
        //     cout << foodvector[i].getDetails() << endl;
        // }

        // for (int i = 0; i < drinkvector.size(); ++i)
        // {
        //     cout << drinkvector[i].getDetails() << endl;
        // }

        //! Food Maker and Coffee Maker check stock here

        string name;

        cout << "Patron name: ";
        cin >> name;

        //// Patron enters the cafe
        Patron patron(name);
        Order order;

        cout << "Hi " << patron.getName() << "! Welcome to SAJA Café";
        bool again = true;
        // order more
        while(again)
        {
            cout << "> What do you want to order?" << endl;
            cout << "1. Food    2. Coffee" << endl;
            int itemType;
            cout << "Enter number here";
            cin >> itemType;

            if (itemType == 1)
            {
                cout << "Food menu:" << endl;
                for (int i = 0; i < foodvector.size(); ++i)
                {
                    cout << i + 1 << ": " << foodvector[i].getName() << endl;
                }
            }
            else if (itemType == 2)
            {
                cout << "Coffee menu:" << endl;
                for (int i = 0; i < drinkvector.size(); ++i)
                {
                    cout << i + 1 << ": " << drinkvector[i].getName() << endl;
                }
            }

            cout << "Enter number here: ";
            int menuNumber;
            cin >> menuNumber;
            if (itemType == 1)
            {
                order.addItem(new Food(foodvector[menuNumber - 1].getName()));
            }
            else if (itemType == 2)
            {
                order.addItem(new Food(drinkvector[menuNumber - 1].getName()));   
            }

            cout << "> Order more (y/n) : ";
            string answer;
            cin>> answer;

            if (answer == "y"){
                continue;
            }
            else if(answer == "n"){
                again = false;
            }
        }


        //// Patron gives order to the host
        // Order order;
        // order.addItem(new Food("Candy Bar"));
        // order.addItem(new Food("Chocolate Mousse"));
        // order.addItem(new BlackCoffee());
        // order.addItem(new WhiteCoffee());

        //// host take order from patron and forwards to manager
        // host.takeOrder(&patron, &order);
        cout << "Order complete, Next customer (y/n): ";
        string next;
        cin >> next;
        if (next == "y"){
            continue;
        }
        else if(next == "n"){
            Active = false;
        }
    }
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
    return 0;

}

