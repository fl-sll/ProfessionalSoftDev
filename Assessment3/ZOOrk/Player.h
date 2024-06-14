#ifndef ZOORK_PLAYER_H
#define ZOORK_PLAYER_H

#include "Character.h"
#include "Location.h"
#include "NullRoom.h"
#include "Room.h"
#include "Item.h" // Include Item.h for shared_ptr<Item>
#include <vector>
#include <algorithm>
#include <memory>

class NPC; // Forward declaration of NPC class
class Room;
class NullRoom;
class Player : public Character
{
public:
    static Player *instance()
    {
        if (!playerInstance)
        {
            playerInstance = new Player();
        }
        return Player::playerInstance;
    }

    void setCurrentRoom(Room *);
    Room *getCurrentRoom() const;

    void addItem(std::shared_ptr<Item> item);
    void removeItem(const std::string &itemName);
    bool hasItem(const std::string &itemName) const;
    void showInventory() const;
    std::shared_ptr<Item> takeItem(const std::string &itemName);

    void useWeapon(std::shared_ptr<Item> weapon, NPC &npc); // Forward declaration of NPC class

    void usePotion(std::shared_ptr<Item> potion);

    Player(const Player &) = delete;
    Player &operator=(const Player &) = delete;

private:
    static Player *playerInstance;
    Room *currentRoom;
    std::vector<std::shared_ptr<Item>> inventory;

    Player() : Character("You", "You are a person, alike in dignity to any other, but uniquely you.") {}
};

#endif // ZOORK_PLAYER_H

// //
// // Created by Richard Skarbez on 5/7/23.
// //

// #ifndef ZOORK_PLAYER_H
// #define ZOORK_PLAYER_H

// #include "Character.h"
// #include "Location.h"
// #include "NullRoom.h"

// #include <vector>
// #include <algorithm>

// class Player : public Character {
// public:
//     static Player *instance() {
//         // Note: lazy instantiation of the singleton Player object
//         if (!playerInstance) {
//             playerInstance = new Player();
//         }
//         return Player::playerInstance;
//     }

//     void setCurrentRoom(Room*);
//     Room* getCurrentRoom() const;

//     void addItem(const Item& item);
//     void removeItem(const std::string& itenName);
//     bool hasItem(const std::string& itemname) const;
//     void showInventory() const;

//     Player(const Player &) = delete;
//     Player &operator=(const Player &) = delete;

// private:
//     static Player *playerInstance;
//     Room* currentRoom;
//     std::vector<Item> inventory;

//     Player() : Character("You", "You are a person, alike in dignity to any other, but uniquely you."),
//                currentRoom(new NullRoom()) {}
// };

// #endif //ZOORK_PLAYER_H