#ifndef MANAGER_H
#define MANAGER_H

#include "food.hpp"
#include "coffee.hpp"
#include "host.hpp"
#include <string>
#include <vector>

class Manager {
public:
  void receive_order(const std::vector<Food>& food_items, const std::vector<std::pair<std::string, int>>& drink_items);
  void order_complete(Host& host);

private:
  void make_food(const Food& food);
  void prepare_coffee(Coffee& coffee);
};

#endif // MANAGER_H
