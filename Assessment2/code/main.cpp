#include "././headers/patron.hpp"
#include "././headers/host.hpp"
#include "././headers/manager.hpp"
#include <vector>

int main() {
  Patron patron("Alice");
  patron.place_order({Food()}, {{"white", 2}}); // Order chips and white coffee with 2 sugars

  Manager manager;
  Host host(manager);
  host.take_order(patron);

  // Manager calls FoodMaker and CoffeeMaker to prepare the order
  // ... (implementation details)

  manager.order_done(host);

  return 0;
}
