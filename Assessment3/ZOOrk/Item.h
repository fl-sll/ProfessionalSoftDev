#ifndef ZOORK_ITEM_H
#define ZOORK_ITEM_H

#include <memory>
#include "Command.h"
#include "GameObject.h"
#include "NullCommand.h"

class Item : public GameObject {
public:
    Item(const std::string &, const std::string &);
    Item(const std::string &, const std::string &, std::shared_ptr<Command>);

    virtual void use();
    std::string getName() const;
    std::string getDescription() const;

    void setUseCommand(std::shared_ptr<Command>);

protected:
    std::shared_ptr<Command> useCommand;
};

class Object : public Item {
public:
    Object(const std::string &name, const std::string &description) : Item(name, description) {}
};

#endif //ZOORK_ITEM_H