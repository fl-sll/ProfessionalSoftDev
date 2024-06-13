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

// class Weapon : public Item {
// public:
//     Weapon(const std::string &name, const std::string &description, int damage)
//         : Item(name, description), damage(damage) {}

//     int getDamage() const {
//         return damage;
//     }

// private:
//     int damage;
// };

// class Potion : public Item {
// public:
//     Potion(const std::string &name, const std::string &description, int healingAmount)
//         : Item(name, description), healingAmount(healingAmount) {}

//     int getHealingAmount() const {
//         return healingAmount;
//     }

// private:
//     int healingAmount;
// };

#endif //ZOORK_ITEM_H











// //
// // Created by Richard Skarbez on 5/7/23.
// //

// #ifndef ZOORK_ITEM_H
// #define ZOORK_ITEM_H

// #include <memory>

// #include "Command.h"
// #include "GameObject.h"
// #include "NullCommand.h"

// class Item : public GameObject {
// public:
//     Item(const std::string &, const std::string &);

//     Item(const std::string &, const std::string &, std::shared_ptr<Command>);

//     virtual void use();

//     void setUseCommand(std::shared_ptr<Command>);

// protected:
//     std::shared_ptr<Command> useCommand;
// };

// #endif //ZOORK_ITEM_H
