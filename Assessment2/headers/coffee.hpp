#ifndef COFFEE_H
#define COFFEE_H

#include <string>
#include <iostream>
#include "drink.hpp"

using namespace std;


class Coffee : public Drink {
public:
    virtual ~Coffee() {}
    virtual string getName() const = 0;
    virtual string getMilkType() const = 0;
};

#endif 
