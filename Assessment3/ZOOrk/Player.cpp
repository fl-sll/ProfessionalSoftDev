#include "Player.h"
#include "NPC.h"
#include <iostream>

Player *Player::playerInstance = nullptr;

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

Room* Player::getCurrentRoom() const {
    return currentRoom;
}

void Player::addItem(std::shared_ptr<Item> item) {
    inventory.push_back(item);
}

void Player::removeItem(const std::string& itemName) {
    struct ItemNameMatcher {
        const std::string& targetName;
        ItemNameMatcher(const std::string& name) : targetName(name) {}
        bool operator()(const std::shared_ptr<Item>& item) const {
            return item->getName() == targetName;
        }
    };

    ItemNameMatcher matcher(itemName);
    auto it = std::remove_if(inventory.begin(), inventory.end(), matcher);
    if (it != inventory.end()) {
        inventory.erase(it, inventory.end());
    }
}

std::shared_ptr<Item> Player::takeItem(const std::string& itemName)
{
    auto it = std::find_if(inventory.begin(), inventory.end(), [&](const std::shared_ptr<Item> &item)
                           { return item->getName() == itemName; });
    if (it != inventory.end())
    {
        std::shared_ptr<Item> item = *it;
        inventory.erase(it);
        return item;
    }
    throw std::runtime_error("Item not found");
}

std::shared_ptr<Item> Player::getItem(const std::string& itemName)
{
    auto it = std::find_if(inventory.begin(), inventory.end(), [&](const std::shared_ptr<Item> &item)
                           { return item->getName() == itemName; });
    if (it != inventory.end())
    {
        std::shared_ptr<Item> item = *it;
        return item;
    }
    throw std::runtime_error("Item not found");
}


bool Player::hasItem(const std::string& itemName) const {
    struct ItemNameMatcher {
        const std::string& targetName;
        ItemNameMatcher(const std::string& name) : targetName(name) {}
        bool operator()(const std::shared_ptr<Item>& item) const {
            return item->getName() == targetName;
        }
    };

    ItemNameMatcher matcher(itemName);
    return std::any_of(inventory.begin(), inventory.end(), matcher);
}

void Player::showInventory() const {
    if (inventory.empty()) {
        std::cout << "Your inventory is empty." << std::endl;
    } else {
        std::cout << "You are carrying: " << std::endl;
        for (const auto& item : inventory) {
            std::cout << "- " << item->getName() << std::endl;
        }
    }
}

void Player::interactWithNPC(std::shared_ptr<NPC> npc, std::string& itemName) {
    npc->interact(*this, itemName);
}
