#include "././headers/host.hpp"
#include <iostream>

Host::Host(Manager& manager) : manager_(manager) {}

void Host::take_order(const Patron& patron) {
  // Implement logic to take order from patron (e.g., user input)
  // ... (modify order based on user input)
  manager_.receive_order(patron.get_order().get_food_items(), patron.get_order().get_drink_items());
  manager_.order_complete(patron);
}

void Host::notify_complete(const Patron& patron) {
  std::cout << "Your order is complete, " << patron.get_name() << std::endl;
}
