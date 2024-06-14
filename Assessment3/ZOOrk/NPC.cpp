#include "NPC.h"
#include <iostream>

NPC::NPC(const std::string& name, const std::string& description, const std::string& dialogue, const std::string& defeatItem)
    : Character(name, description), dialogue(dialogue), defeatItem(defeatItem), defeated(false) {}

NPC::~NPC() {}


std::string NPC::getName() const{
    return name;
};
    
std::string NPC::getDescription() const{
    return description;
};


std::string NPC::getDialogue() const {
    return dialogue;
}

void NPC::setDialogue(const std::string& dialogue) {
    this->dialogue = dialogue;
}

void NPC::interact(Player& player) {
    if (!isDefeated()) {
        if(player.hasItem(defeatItem)) {
            defeated = true;
            std::cout << "You defeated " << name << " with " << defeatItem << std::endl;
        }
        else {
            std::cout << "You don't have the right item to defeat " << name << std::endl;
        }
    }
    else {
        std::cout << name << " is already defeated!" << std::endl;
    }
}

bool NPC::isDefeated() const {
    return defeated;
}