#ifndef FOOD_H
#define FOOD_H

class Food {
public:
  virtual ~Food() = default;
  // Implement methods for food items (e.g., name, price)
  virtual std::string get_name() const = 0;
  virtual double get_price() const = 0;
};

#endif // FOOD_H
