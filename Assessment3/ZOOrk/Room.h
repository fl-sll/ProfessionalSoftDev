//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_ROOM_H
#define ZOORK_ROOM_H

#include "Character.h"
#include "RoomDefaultEnterCommand.h"
#include "Item.h"
#include "Location.h"
#include "NPC.h"
#include <map>
#include <algorithm>

// class NullRoom;
class Passage;
class NPC;

class Room : public Location
{
public:
    Room(const std::string &, const std::string &);
    Room(const std::string &, const std::string &, std::shared_ptr<Command>);

    void addItem(std::shared_ptr<Item> item);
    void removeItem(const std::string &itemName);
    bool hasItem(const std::string &itemName) const;
    std::shared_ptr<Item> takeItem(const std::string &itemName);

    void addCharacter(std::shared_ptr<NPC> npc);
    void removeCharacter(const std::string &npc);
    void getCharacter() const;
    bool hasCharacter(const std::string &npcName) const;
    std::shared_ptr<NPC> getNPC(const std::string &npcName);

    void addPassage(const std::string &, std::shared_ptr<Passage>);
    void removePassage(const std::string &);
    std::shared_ptr<Passage> getPassage(const std::string &);
    std::string getName() const;
    std::string getDescription() const;
    void getItem() const;

protected:
    std::vector<std::shared_ptr<NPC>> characters;
    std::map<std::string, std::shared_ptr<Passage>> passageMap;

private:
    std::string name;
    std::string description;
    std::vector<std::shared_ptr<Item>> items;
};

#endif // ZOORK_ROOM_H
