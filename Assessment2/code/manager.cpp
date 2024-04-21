#include "././headers/manager.hpp"
#include "././headers/foodmaker.hpp" // Include FoodMaker header (assuming implementation)
#include "././headers/coffeemaker.hpp" // Include CoffeeMaker header (assuming implementation)
#include <iostream>

void Manager::receive_order(const std::vector<Food>& food_items, const std::vector<std::pair<std::string, int>>& drink_items) {
  for (const Food& food : food_items) {
    make_food(food);
  }
  for (const auto& drink : drink_items) {
    std::unique_ptr<Coffee> coffee = CoffeeMaker::create_coffee(drink.first, drink.second);
    prepare_coffee(*coffee);
  }
}

void Manager::order_complete(Host& host) {
  host.notify_complete(host); // Inform Host when order is ready
}

void Manager::make_food(const Food& food) {
  // Simulate food preparation using Food methods
  std::cout << "Preparing " << food.get_name() << " ..." << std::endl;
}

void Manager::prepare_coffee(Coffee& coffee) {
  // Simulate coffee preparation using Coffee methods (e.g., adding milk/sugar)
  std::cout << "Preparing " << coffee.get_sugars()  << "-sugar coffee..." << std::endl;
}
