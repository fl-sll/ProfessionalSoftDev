#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "menuitem.h"

class Order {
public:
    void addItem(MenuItem* item);
    const std::vector<MenuItem*>& getItems() const;

private:
    std::vector<MenuItem*> items;
};

#endif  // ORDER_H