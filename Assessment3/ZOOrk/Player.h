#ifndef ZOORK_PLAYER_H
#define ZOORK_PLAYER_H

#include "Character.h"
#include "Location.h"
#include "NullRoom.h"
#include "Room.h"
#include "Item.h"
#include <vector>
#include <algorithm>
#include <memory>

class NPC;
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
    void setPrison(Room *);
    Room *getPrison() const;

    void addItem(std::shared_ptr<Item> item);
    void removeItem(const std::string &itemName);
    bool hasItem(const std::string &itemName) const;
    void showInventory() const;
    std::shared_ptr<Item> takeItem(const std::string &itemName);

    void interactWithNPC(std::shared_ptr<NPC> npc);

    Player(const Player &) = delete;
    Player &operator=(const Player &) = delete;

private:
    static Player *playerInstance;
    Room *currentRoom;
    Room *prison;
    std::vector<std::shared_ptr<Item>> inventory;

    Player() : Character("You", "You are a person, alike in dignity to any other, but uniquely you.") {}
};

#endif // ZOORK_PLAYER_H
