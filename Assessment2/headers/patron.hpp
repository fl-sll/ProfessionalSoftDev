#ifndef PATRON_H
#define PATRON_H

#include "food.hpp"
#include "order.hpp"
#include <string>
#include <vector>

class Patron {
public:
  Patron(const std::string& name);

  void place_order(const std::vector<Food>& food_items, const std::vector<std::pair<std::string, int>>& drink_items);

  const std::string& get_name() const { return name_; }
  const Order& get_order() const { return order_; }

private:
  std::string name_;
  Order order_;
};

#endif // PATRON_H
