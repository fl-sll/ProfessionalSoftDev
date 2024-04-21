#ifndef COFFEE_H
#define COFFEE_H

#include "drink.hpp" // Include Drink header

class Coffee : public Drink {
public:
  Coffee(int sugars = 0);
  int get_sugars() const { return sugars_; }

private:
  int sugars_;
};

#endif // COFFEE_H
