#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <iostream>
#include "food.hpp"
#include "drink.hpp"

using namespace std;

class Order {
public:
    void addItem(Food* food);
    void addItem(Drink* drink);
    bool isReady() const;
    void displayOrder() const;
private:
    vector<Food*> foods;
    vector<Drink*> drinks;
    bool foodReady;
    bool coffeeReady;
};

#endif 
