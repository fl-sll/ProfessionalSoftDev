#include "./../header/coffee.h"
#include <sstream>

Coffee::Coffee(std::string name, int sugar, int stock) : name(name), sugars(sugar), stock(stock) {}

std::string Coffee::getName() const
{
    return name;
}

int Coffee::getStock() const
{
    return stock;
}

int Coffee::getSugar() const{
    return sugars;
}

void Coffee::addSugar(int amount)
{
    sugars += amount;
}
void Coffee::addStock(int amount)
{
    stock += amount;
}

void Coffee::delStock() {
    // if (stock > 0)
    // {
    //     stock--;
    // }
    cout << "Test";
}

std::string Coffee::getDetails()
{
    std::stringstream ss;
    ss << name << " has " << sugars << " sugar. Stock = " << stock;
    return ss.str();
}

BlackCoffee::BlackCoffee() : Coffee("Black Coffee", 0, stock) {}

WhiteCoffee::WhiteCoffee() : Coffee("White Coffee", 4, stock) {}
