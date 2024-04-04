#include "order.hpp"
#include <iostream>

using namespace std;

void Order::addItem(Food* food) {
    foods.push_back(food);
    cout << "Added " << food->getName() << " to the order.\n";
}

void Order::addItem(Drink* drink) {
    drinks.push_back(drink);
    cout << "Added " << drink->getName() << " to the order.\n";
}

bool Order::isReady() const {
    return foodReady && coffeeReady;
}

void Order::displayOrder() const {
    cout << "Items in the order:\n";
    for (const auto& food : foods) {
        cout << "- " << food->getName() << "\n";
    }
    for (const auto& drink : drinks) {
        cout << "- " << drink->getName() << "\n";
    }
}
