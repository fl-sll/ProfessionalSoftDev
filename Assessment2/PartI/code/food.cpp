#include "./../header/food.h"
#include <sstream>

Food::Food(std::string name) : name(name){};

std::string Food::getName() const
{
    return name;
}

std::string Food::getDetails()
{
    std::stringstream ss;
    ss << name << ". Stock = " << stock;
    return ss.str();
}

void Food::addStock(int amount){
    stock += amount;
}
