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


int main()
{
    std::pair<std::vector<Coffee>, std::vector<Food> > r = readMenu();
    std::vector<Coffee> drinkvector = r.first;
    std::vector<Food> foodvector = r.second;
    
    //// Create objects
    Host host;
    Manager manager;
    FoodMaker foodMaker = FoodMaker(foodvector);
    CoffeeMaker coffeeMaker = CoffeeMaker(drinkvector);

    //// Set relationships between objects
    host.setManager(&manager);
    manager.setHost(&host);
    manager.setFoodMaker(&foodMaker);
    manager.setCoffeeMaker(&coffeeMaker);
    foodMaker.setManager(&manager);
    coffeeMaker.setManager(&manager);

    // repeat for next customer, end to close shift
    bool Active = true;
    while (Active) {
        std::string name;

        std::cout << "Patron name: ";
        std::cin >> name;

        //// Patron enters the cafe
        Patron patron(name);
        Order order;

        std::cout << "Hi " << patron.getName() << "! Welcome to SAJA Cafe!" << std::endl;
        bool again = true;

        //// order more
        while(again) {
            std::cout << "> What do you want to order?" << std::endl;
            std::cout << "1. Food    2. Coffee" << std::endl;
            int itemType;
            std::cout << "Enter number here: ";
            std::cin >> itemType;

            if (itemType == 1) {
                std::cout << "Food menu:" << std::endl;
                for (int i = 0; i < foodvector.size(); ++i) {
                    std::cout << i + 1 << ": " << foodvector[i].getName() << std::endl;
                }
            }
            else if (itemType == 2) {
                std::cout << "Coffee menu:" << std::endl;
                for (int i = 0; i < drinkvector.size(); ++i) {
                    std::cout << i + 1 << ": " << drinkvector[i].getName() << std::endl;
                }
            }
            else {
                continue;
                
            }

            while(true) {
                std::cout << "Enter number here: ";
                int menuNumber;
                std::cin >> menuNumber;

                if (itemType == 1 && menuNumber <= foodvector.size()) {
                    if(foodvector[menuNumber-1].getStock()!=0) {
                        order.addItem(new Food(foodvector[menuNumber - 1].getName(), foodvector[menuNumber - 1].getStock()));
                        std::cout << foodvector[menuNumber - 1].getName() << " ordered" << std::endl;
                        break;
                    }
                    else {
                        std::cout << "Sorry, we ran out of " << foodvector[menuNumber - 1].getName() <<std::endl;
                        break;
                    }
                }
                else if (itemType == 2 && menuNumber <= drinkvector.size()) {
                    if(drinkvector[menuNumber-1].getStock()!=0) {
                        std::cout << "Enter sugar pack amount: ";
                        int sugar;
                        std::cin >> sugar;
                        order.addItem(new Coffee(drinkvector[menuNumber - 1].getName(), sugar, drinkvector[menuNumber - 1].getStock()));
                        std::cout << drinkvector[menuNumber - 1].getName() << " with " << sugar  << " sugar pack(s) ordered" << std::endl;
                        break;
                    }
                    else {
                        std::cout << "Sorry, we ran out of " << drinkvector[menuNumber - 1].getName() <<std::endl;
                        break;
                    }
                    
                }
                else {
                    continue;
                }
            }

            std::cout << "> Order more (y/n) : ";
            std::string answer;
            std::cin>> answer;

            if (answer == "y" || answer == "Y" || answer == "Yes" || answer == "YES" || answer == "yes" || answer == "yEs"|| answer == "yeS"|| answer == "YEs" || answer == "yES"|| answer == "YeS") {
                continue;
            }
            else if(answer == "n" || answer == "N" || answer == "NO" || answer == "No" || answer == "no" || answer == "nO") {
                again = false;
            }
        }
        
        //// host take order from patron and forwards to manager
        host.takeOrder(&patron, &order);
        std::cout << "Order complete, Next customer (y/n): ";
        std::string next;
        std::cin >> next;
        if (next == "y"){
            continue;
        }
        else if(next == "n"){
            Active = false;
        }
    }

    std::cout << "Thanks for the orders!!!" << std::endl;

    return 0;
}