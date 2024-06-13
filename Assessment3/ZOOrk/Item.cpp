//
// Created by Richard Skarbez on 5/7/23.
//

#include "Item.h"

#include <utility>

Item::Item(const std::string &n, const std::string &d) : GameObject(n, d),
                                                         useCommand(std::make_shared<NullCommand>()) {
                                                            name = n;
                                                            description = d;
<<<<<<< HEAD
                                                        }
=======
                                                         }
>>>>>>> master

Item::Item(const std::string &n, const std::string &d, std::shared_ptr<Command> c) : GameObject(n, d),
                                                                                     useCommand(std::move(c)) {
                                                                                        name = n;
                                                                                        description = d;
<<<<<<< HEAD
                                                                                     }
=======
>>>>>>> master

                                                                                     }

// TODO 
void Item::use() {
    useCommand->execute();
}

void Item::setUseCommand(std::shared_ptr<Command> c) {
    useCommand = c;
}
<<<<<<< HEAD
std::string Item::getName() const{
    return name;
}

std::string Item::getDescription() const{
=======

std::string Item::getName(){
    return name;
}

std::string Item::getDescription(){
>>>>>>> master
    return description;
}