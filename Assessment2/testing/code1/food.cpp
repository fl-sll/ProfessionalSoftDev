#include "./../header1/food.h"

Food::Food(std::string name) : name(name) {}

std::string Food::getName() const {
    return name;
}
