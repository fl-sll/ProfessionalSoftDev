#ifndef ZOORK_NPC_H
#define ZOORK_NPC_H

#include "Character.h"
#include "Player.h"
#include <string>

class Player;

class NPC : public Character {
public:
    NPC(const std::string& name, const std::string& description, const std::string& dialogue, const std::string& defeatItem);
    ~NPC();

    std::string getName() const;
    std::string getDescription() const;
    std::string getDialogue() const;
    void setDialogue(const std::string& dialogue);


    void interact(Player& player);
    bool isDefeated() const;


private:
    std::string dialogue;
    std::string defeatItem;
    bool defeated;
};

#endif //ZOORK_NPC_H