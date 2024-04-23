#include "./../header1/patron.h"
#include <iostream>

class MenuItem;
class Manager;

Patron::Patron(std::string name) : name(name) {}

std::string Patron::getName() const {
    return name;
}
