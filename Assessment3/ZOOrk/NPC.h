#ifndef ZOORK_NPC_H
#define ZOORK_NPC_H

#include "Character.h"
#include "Player.h"
#include <string>

class Player;

class NPC : public Character {
public:
    // enum class NPCType { FRIENDLY, HOSTILE };

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
    // NPCType type;
    // int attackPower;

    // void friendlyInteract(Player& player);
    // void hostileInteract(Player& player);
};

#endif //ZOORK_NPC_H




// #ifndef ZOORK_NPC_H
// #define ZOORK_NPC_H

// #include "Character.h"
// #include "Player.h"
// #include <string>
// #include <vector>

// class NPC : public Character {
// public:
//     enum class NPCType { FRIENDLY, HOSTILE };

//     NPC(const std::string& name, const std::string& description, const std::string& dialogue, NPCType type, int attackPower);
//     ~NPC();

//     std::string getDialogue() const;
//     void setDialogue(const std::string& dialogue);

//     NPCType getType() const;
//     void setType(NPCType type);

//     void interact(Player& player); // Method for NPC-specific interactions

// private:
//     std::string dialogue;
//     NPCType type;
//     int attackPower;

//     void friendlyInteract(Player& player);
//     void hostileInteract(Player& player);
// };

// #endif //ZOORK_NPC_H
