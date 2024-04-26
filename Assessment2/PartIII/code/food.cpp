#include "./../header/food.h"
#include <sstream>

Food::Food(std::string name, int stock) : name(name), stock(stock) {}

std::string Food::getName() const
{
    return name;
}

int Food::getStock() const{
    return stock;
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

// void Food::delStock(){
//     // if (stock > 0)
//     // {
//     //     stock--;
//     // }
//     cout << "Test"
// }