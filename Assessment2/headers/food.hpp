#ifndef FOOD_H
#define FOOD_H

#include <string>
#include <iostream>

using namespace std;

class Food {
public:
    virtual ~Food() {}
    virtual string getName() const = 0;
};

#endif 
