#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <string>

class MenuItem {
public:
    virtual ~MenuItem() {}
    virtual std::string getName() const = 0;
    virtual int getStock() const=0;
    void delStock();
};

#endif  // MENU_ITEM_H
