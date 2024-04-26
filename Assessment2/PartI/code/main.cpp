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

    // repeat for next customer, end to close shift
    bool Active = true;
    while (Active)
    {
        // readMenu();

        pair<vector<Coffee>, vector<Food> > r = readMenu();
        vector<Coffee> drinkvector = r.first;
        vector<Food> foodvector = r.second;

        string name;

        std::cout << "Patron name: ";
        cin >> name;

        //// Patron enters the cafe
        Patron patron(name);
        Order order;

        std::cout << "Hi " << patron.getName() << "! Welcome to SAJA Cafe !" << endl;
        bool again = true;
        // order more
        while(again)
        {
            std::cout << "> What do you want to order?" << endl;
            std::cout << "1. Food    2. Coffee" << endl;
            int itemType;
            std::cout << "Enter number here: ";
            cin >> itemType;

            if (itemType == 1)
            {
                std::cout << "Food menu:" << endl;
                for (int i = 0; i < foodvector.size(); ++i)
                {
                    std::cout << i + 1 << ": " << foodvector[i].getName() << endl;
                }
            }
            else if (itemType == 2)
            {
                std::cout << "Coffee menu:" << endl;
                for (int i = 0; i < drinkvector.size(); ++i)
                {
                    std::cout << i + 1 << ": " << drinkvector[i].getName() << endl;
                }
            }
            else{
                continue;
            }

            while(true){std::cout << "Enter number here: ";
            int menuNumber;
            cin >> menuNumber;
            if (itemType == 1 && menuNumber <= foodvector.size())
            {
                order.addItem(new Food(foodvector[menuNumber - 1].getName()));
                cout << foodvector[menuNumber - 1].getName() << " ordered" << endl;
                break;
            }
            else if (itemType == 2 && menuNumber <= drinkvector.size())
            {
                cout << "Enter sugar pack amount: ";
                int sugar;
                cin >> sugar;   
                // MenuItem drink = new Coffee(drinkvector[menuNumber - 1].getName(), sugar);
                order.addItem(new Coffee(drinkvector[menuNumber - 1].getName(), sugar));
                cout << drinkvector[menuNumber - 1].getName() << " with " << sugar  << " sugar pack(s) ordered" << endl;
                break;
            }else{
                continue;
            }
            }

            std::cout << "> Order more (y/n) : ";
            string answer;
            cin>> answer;

            if (answer == "y" || answer == "Y" || answer == "Yes" || answer == "YES" || answer == "yes" || answer == "yEs"|| answer == "yeS"|| answer == "YEs" || answer == "yES"|| answer == "YeS"){
                continue;
            }
            else if(answer == "n" || answer == "N" || answer == "NO" || answer == "No" || answer == "no" || answer == "nO"){
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
        host.takeOrder(&patron, &order);
        std::cout << "Order complete, Next customer (y/n): ";
        string next;
        cin >> next;
        if (next == "y"){
            continue;
        }
        else if(next == "n"){
            Active = false;
        }
    }
    std::cout << "Closing shift. Goodnight!" << endl;
    return 0;

}

