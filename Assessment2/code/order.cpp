#include "./../header/order.h"

void Order::addItem(MenuItem* item) {
    items.push_back(item);
};

const std::vector<MenuItem*>& Order::getItems() const {
    return items;
}
