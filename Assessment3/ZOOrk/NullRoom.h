//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_NULLROOM_H
#define ZOORK_NULLROOM_H

#include "Room.h"

class NullRoom : public Room
{
public:
    NullRoom();

// private:
    // NullRoom() : Room("Nowhere", "This is a nonplace.", std::make_shared<NullCommand>()) {}
};

#endif // ZOORK_NULLROOM_H
