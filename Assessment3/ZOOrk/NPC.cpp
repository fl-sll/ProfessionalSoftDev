#include "NPC.h"
#include <iostream>

NPC::NPC(const std::string& name, const std::string& description, const std::string& dialogue, NPCType type, int attackPower)
    : Character(name, description), dialogue(dialogue), type(type), attackPower(attackPower) {}

NPC::~NPC() {}

std::string NPC::getDialogue() const {
    return dialogue;
}

void NPC::setDialogue(const std::string& dialogue) {
    this->dialogue = dialogue;
}

NPC::NPCType NPC::getType() const {
    return type;
}

void NPC::setType(NPCType type) {
    this->type = type;
}

void NPC::interact(Player& player) {
    if (type == NPCType::FRIENDLY) {
        friendlyInteract(player);
    } else if (type == NPCType::HOSTILE) {
        hostileInteract(player);
    }
}

void NPC::friendlyInteract(Player& player) {
    std::cout << getName() << " says: " << getDialogue() << std::endl;
    auto hintItem = std::make_shared<Object>("Hint Note", "A note with a hint for your next step.");
    player.addItem(hintItem);
    std::cout << getName() << " gives you a hint note." << std::endl;
}

void NPC::hostileInteract(Player& player) {
    std::cout << getName() << " attacks you!" << std::endl;
    player.takeDamage(attackPower);
    std::cout << "You take " << attackPower << " damage. Your health is now " << player.getHealth() << "." << std::endl;
}

void NPC::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

bool NPC::isDefeated() const {
    return health <= 0;
}
