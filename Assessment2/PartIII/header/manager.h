#ifndef MANAGER_H
#define MANAGER_H

#include "host.h"
#include "foodmaker.h"
#include "food.h"
#include "coffeemaker.h"
#include "coffee.h"
#include "order.h"
#include "patron.h"

class Manager {
public:
    void receiveOrder(Patron* patron, Order* order);
    void setFoodMaker(FoodMaker* maker);
    void setCoffeeMaker(CoffeeMaker* maker);
    void setHost(Host* hst);
    void coffeeReady();
    void foodReady();

private:
    FoodMaker* foodMaker;
    CoffeeMaker* coffeeMaker;
    Host* host;
};

#endif  // MANAGER_H