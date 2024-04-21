#ifndef FOODMAKER_H
#define FOODMAKER_H

#include "food.hpp"
#include <string>

class FoodMaker {
public:
  static FoodMaker& get_instance(); // Singleton pattern

  // Implement methods for making and providing pre-packaged food
  virtual Food* make_food(const std::string& food_name) = 0;

private:
  FoodMaker() = default;
  FoodMaker(const FoodMaker&) = delete;
  FoodMaker& operator=(const FoodMaker&) = delete;
};

#endif // FOODMAKER_H
