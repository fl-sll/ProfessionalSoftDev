#ifndef DRINK_H
#define DRINK_H

#include <string>
#include <iostream>

using namespace std;

class Drink {
public:
    virtual ~Drink() {}
    virtual string getName() const = 0;
};

#endif 
