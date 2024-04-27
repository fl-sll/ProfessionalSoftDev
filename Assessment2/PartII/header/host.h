#ifndef HOST_H
#define HOST_H

#include <string>
class Patron;
class Manager;
class Order;

class Host {
public:
    void takeOrder(Patron* patron, Order* order);
    void notifyPatron(std::string name, Order* order);
    void setManager(Manager* mgr);
private:
    Manager* manager;
};

#endif  // HOST_H
