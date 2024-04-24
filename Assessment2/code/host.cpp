#include "./../header/host.h"
#include "./../header/manager.h"
#include <iostream>

void Host::takeOrder(Patron* patron, Order* order) {
    manager->receiveOrder(patron, order);
}

void Host::notifyPatron(std::string name, Order* order) {
    std::cout << "Order for " << name << " is ready:" << std::endl;
    for (auto item : order->getItems()) {
        std::cout << "- " << item->getName() << std::endl;
    }
}

void Host::setManager(Manager* mgr) {
    manager = mgr;
}
