#include <iostream>
#include <vector>
#include <memory> // For smart pointers
#include <stdlib.h>

// Define base classes
class Food {
public:
  virtual ~Food() = default;
  // Implement methods for food items (e.g., name, price)
};

class Drink {
public:
  virtual ~Drink() = default;
  // Implement methods for drinks (e.g., name, price)
};

// Define coffee types
class Coffee : public Drink {
public:
  Coffee(int sugars = 0) : sugars_(sugars) {}
  int get_sugars() const { return sugars_; }

private:
  int sugars_;
};

class BlackCoffee : public Coffee {
public:
  BlackCoffee() : Coffee(0) {}
};

class WhiteCoffee : public Coffee {
public:
  WhiteCoffee(int sugars) : Coffee(sugars) {}
};

// Singleton for FoodMaker (limited resources)
class FoodMaker {
public:
  static FoodMaker& get_instance() {
    static FoodMaker instance;
    return instance;
  }

  // Implement methods for making and providing pre-packaged food

private:
  FoodMaker() = default;
  FoodMaker(const FoodMaker&) = delete;
  FoodMaker& operator=(const FoodMaker&) = delete;
};

// Factory Method for CoffeeMaker
class CoffeeMaker {
public:
  static std::unique_ptr<Coffee> create_coffee(const std::string& coffee_type, int sugars) {
    if (coffee_type == "black") {
      return std::make_unique<BlackCoffee>();
    } else if (coffee_type == "white") {
      return std::make_unique<WhiteCoffee>(sugars);
    } else {
      throw std::invalid_argument("Invalid coffee type");
    }
  }
};

// Order collection class
class Order {
public:
  void add_food(const Food& food) { food_items_.push_back(food); }
  void add_drink(const std::pair<std::string, int>& drink) { drink_items_.push_back(drink); }

  const std::vector<Food>& get_food_items() const { return food_items_; }
  const std::vector<std::pair<std::string, int>>& get_drink_items() const { return drink_items_; }

private:
  std::vector<Food> food_items_;
  std::vector<std::pair<std::string, int>> drink_items_; // (coffee_type, sugars)
};

// Patron class
class Patron {
public:
  Patron(const std::string& name) : name_(name) {}

  void place_order(const std::vector<Food>& food_items, const std::vector<std::pair<std::string, int>>& drink_items) {
    for (const Food& food : food_items) {
      order_.add_food(food);
    }
    for (const auto& drink : drink_items) {
      order_.add_drink(drink);
    }
  }

  const std::string& get_name() const { return name_; }
  const Order& get_order() const { return order_; }

private:
  std::string name_;
  Order order_;
};

// Manager class (Mediator)
class Manager {
public:
  void receive_order(const std::vector<Food>& food_items, const std::vector<std::pair<std::string, int>>& drink_items) {
    for (const Food& food : food_items) {
      FoodMaker::get_instance().make_food(food); // Delegate to FoodMaker
    }
    for (const auto& drink : drink_items) {
      std::unique_ptr<Coffee> coffee = CoffeeMaker::create_coffee(drink.first, drink.second); // Delegate to CoffeeMaker factory
      prepare_coffee(*coffee);
    }
  }

  void prepare_coffee(Coffee& coffee) {
    // Simulate coffee preparation using Coffee methods (e.g., adding milk/sugar)
    std::cout << "Preparing " <<  coffee.get_sugars() << "-sugar coffee..." << std::endl;
  }

  void order_complete(Host& host) {
    host.notify_complete(host); // Inform Host when order is ready
  }

private:
  FoodMaker food_maker_; // No longer singleton for demonstration purposes
};

// Host class (Facade)
class Host {
public:
  Host(Manager& manager) : manager_(manager) {};

  void take_order(Patron& patron) {
    manager_.receive_order(patron.get_order().get_food_items(), patron.get_order().get_drink_items());
  }

    void notify_complete(const Patron& patron) {
      std::cout << "Your order is complete, " << patron.get_name() << std::endl;
  }

private:
  Manager& manager_;
};

// Example usage
int main() {
  Patron patron("Alice");
  patron.place_order({Food()}, {{"white", 2}}); // Order chips and white coffee with 2 sugars

  Manager manager;
  Host host(manager);
  host.take_order(patron);

  // Manager calls FoodMaker and CoffeeMaker to prepare the order
  // ... (implementation details)

  manager.order_complete(host);

  return 0;
}
