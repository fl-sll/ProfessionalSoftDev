#include "./../header/patron.h"
#include <iostream>
#include <vector>

class MenuItem;
class Manager;

Patron::Patron(std::string name) : name(name) {}

std::string Patron::getName() const {
    return name;
}