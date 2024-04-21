#ifndef COFFEEMAKER_H
#define COFFEEMAKER_H

#include "coffee.hpp" // Include Coffee header
#include <memory>

class CoffeeMaker {
public:
  static std::unique_ptr<Coffee> create_coffee(const std::string& coffee_type, int sugars);
};

#endif // COFFEEMAKER_H
