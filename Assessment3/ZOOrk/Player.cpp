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
            std::cout << "- " << item->getName() << ": " << item->getDescription() << std::endl;
        }
    }
}

// void Player::useWeapon(std::shared_ptr<Item> weapon, NPC& npc) {
//     auto weaponPtr = std::dynamic_pointer_cast<Weapon>(weapon);
//     if (weaponPtr) {
//         std::cout << "You use " << weapon->getName() << " to attack " << npc.getName() << "." << std::endl;
//         npc.takeDamage(weaponPtr->getDamage());
//         if (npc.isDefeated()) {
//             std::cout << npc.getName() << " is defeated!" << std::endl;
//         } else {
//             std::cout << npc.getName() << " has " << npc.getHealth() << " health remaining." << std::endl;
//         }
//     } else {
//         std::cout << "This item is not a weapon." << std::endl;
//     }
// }

// void Player::usePotion(std::shared_ptr<Item> potion) {
//     auto potionPtr = std::dynamic_pointer_cast<Potion>(potion);
//     if (potionPtr) {
//         std::cout << "You use " << potion->getName() << " and recover " << potionPtr->getHealingAmount() << " health." << std::endl;
//         heal(potionPtr->getHealingAmount());
//         removeItem(potion->getName());
//     } else {
//         std::cout << "This item is not a potion." << std::endl;
//     }
// }






// //
// // Created by Richard Skarbez on 5/7/23.
// //

// #include "Player.h"

// #include <algorithm>

// Player *Player::playerInstance = nullptr;

// void Player::setCurrentRoom(Room* room) {
//     currentRoom = room;
// }

// Room* Player::getCurrentRoom() const {
//     return currentRoom;
// }

// void Player::addItem(const Item& item) {
//     inventory.push_back(item);
// }

// void Player::removeItem(const std::string& itemName) {
//     auto it = std::remove_if(inventory.begin(), inventory.end(), [&](const Item& item) {
//         return item.getName() == itemName;
//     });
//     if (it != inventory.end()) {
//         inventory.erase(it);
//     }
// }

// bool Player::hasItem(const std::string& itemName) const {
//     return std::any_of(inventory.begin(), inventory.end(), [&](const Item& item) {
//         return item.getName() == itemName;
//     });
// }

// void Player::showInventory() const {
//     if (inventory.empty()) {
//         std::cout << "Your inventory is empty" << std::endl;
//     } else {
//         std::cout << "You are carryinng: " << std::endl;
//         for (const auto& item : inventory) {
//             std::cout << "- " << item.getName() << ": " << item.getDescription() << std::endl;
//         }
//     }
// }