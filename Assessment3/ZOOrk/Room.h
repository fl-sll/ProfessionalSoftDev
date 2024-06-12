//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_ROOM_H
#define ZOORK_ROOM_H

#include "Character.h"
#include "RoomDefaultEnterCommand.h"
#include "Item.h"
#include "Location.h"
#include <map>
#include <algorithm>

class Passage;

class Room : public Location {
public:
    Room(const std::string &, const std::string &);
    Room(const std::string &, const std::string &, std::shared_ptr<Command>);

    void addItem(const Item& item);
    void removeItem(const std::string& itemName);
    bool hasItem(const std::string& itemName) const;
    Item takeItem(const std::string& itemName);


//    void addCharacter(Character*);
//    void removeCharacter(const std::string&);
//    Character* getCharacter(const std::string&);

    void addPassage(const std::string &, std::shared_ptr<Passage>);
    void removePassage(const std::string &);
    std::shared_ptr<Passage> getPassage(const std::string &);
    std::string getName() const;
    std::string getDescription() const;

protected:
//    std::vector<Item*> items;
//    std::vector<Character*> characters;
    std::map<std::string, std::shared_ptr<Passage>> passageMap;

private:
    std::string name;
    std::string description;
    std::vector<Item> items;
};



#endif //ZOORK_ROOM_H
