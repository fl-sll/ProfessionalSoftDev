#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "food.hpp"
#include "drink.hpp"

class Order {
public:
  void add_food(const Food& food);
  void add_drink(const std::pair<std::string, int>& drink);

  const std::vector<Food>& get_food_items() const { return food_items_; }
  const std::vector<std::pair<std::string, int>>& get_drink_items() const { return drink_items_; }

private:
  std::vector<Food> food_items_;
  std::vector<std::pair<std::string, int>> drink_items_; // (coffee_type, sugars)
};

#endif // ORDER_H
