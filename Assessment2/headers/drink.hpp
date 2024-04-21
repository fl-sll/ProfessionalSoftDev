#ifndef DRINK_H
#define DRINK_H

#include "food.hpp" // Include Food header

class Drink : public Food {
public:
  virtual ~Drink() = default;
  // Implement methods for drinks (e.g., name, price)
  virtual std::string get_name() const override = 0;
  virtual double get_price() const override = 0;
};

#endif // DRINK_H
