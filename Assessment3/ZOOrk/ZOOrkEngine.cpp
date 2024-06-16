//
// Created by Richard Skarbez on 5/7/23.
//

#include "ZOOrkEngine.h"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
// TODO change this to something global

ZOOrkEngine::ZOOrkEngine(std::shared_ptr<Room> start)
{
    std::ifstream title("title.txt");

    if (title.is_open())
    {
        std::cout << title.rdbuf();
        title.close();
    }
    else
    {
        std::cerr << "Error: could not open file" << std::endl;
    }

    player = Player::instance();
    player->setCurrentRoom(start.get());
    player->getCurrentRoom()->enter();
}

void ZOOrkEngine::run()
{

    while (!gameOver)
    {
        std::cout << "===============================================" << std::endl;
        std::cout << "Enter command\n> ";

        std::string input;
        std::getline(std::cin, input);

        std::vector<std::string> words = tokenizeString(input);
        std::string command = words[0];
        std::vector<std::string> arguments(words.begin() + 1, words.end());

        if (command == "go")
        {
            handleGoCommand(arguments);
        }
        else if (command == "look")
        {
            handleLookCommand(arguments);
        }
        else if (command == "inspect")
        {
            handleInspectCommand(arguments);
        }
        else if (command == "talk")
        {
            handleTalkCommand(arguments);
        }
        else if ((command == "take") || (command == "get"))
        {
            handleTakeCommand(arguments);
        }
        else if (command == "drop")
        {
            handleDropCommand(arguments);
        }
        else if ((command == "quit") || (command == "exit"))
        {
            handleQuitCommand(arguments);
        }
        else if (command == "inventory")
        {
            player->showInventory();
        }
        else if (command == "help")
        {
            handleHelpCommand();
        }
        else if (command == "use")
        {
            handleUseCommand(arguments);
        }
        else
        {
            std::cout << "I don't understand that command.\n";
        }

        if (checkAllNPCsDefeated())
        {
            std::cout << "swoooshh.....   swoooshhh..... (sound of the wind rushing). \nThe realm is shaking!! \nCongratulation, now the realm is opened slowly, You have limited time to escape from the realm and go back to your human realm, GOOO... GOOOO.. before you trapped foreverrr......." << std::endl;
            gameOver = true;
        }
    }
}

void ZOOrkEngine::handleGoCommand(std::vector<std::string> arguments)
{
    if (arguments.empty())
    {
        std::cout << "Go where?" << std::endl;
        return;
    }

    std::string direction;
    if (arguments[0] == "n" || arguments[0] == "north")
    {
        direction = "north";
    }
    else if (arguments[0] == "s" || arguments[0] == "south")
    {
        direction = "south";
    }
    else if (arguments[0] == "e" || arguments[0] == "east")
    {
        direction = "east";
    }
    else if (arguments[0] == "w" || arguments[0] == "west")
    {
        direction = "west";
    }
    else
    {
        direction = arguments[0];
    }

    Room *currentRoom = player->getCurrentRoom();
    auto passage = currentRoom->getPassage(direction);
    if (!passage)
    {
        std::cout << "Invalid direction. You are still in the same room." << std::endl;
    }
    else
    {
        player->setCurrentRoom(passage->getTo());
        passage->enter();
    }
}

void ZOOrkEngine::handleLookCommand(std::vector<std::string> arguments)
{
    Room *currentRoom = player->getCurrentRoom();
    std::cout << "You are currently in " << currentRoom->getName() << std::endl;
    std::cout << currentRoom->getDescription() << std::endl;
    currentRoom->getItem();
    currentRoom->getCharacter();
}

void ZOOrkEngine::handleTalkCommand(std::vector<std::string> arguments)
{
    if (arguments.empty())
    {
        std::cout << "Talk to who?" << std::endl;
        return;
    }
    // get the npc name from user
    std::string bindWord = arguments[0];
    if (bindWord == "to")
    {
        std::string npcName = arguments[1];
        Room *currentRoom = player->getCurrentRoom();
        // check if there's that npc in the room
        if (currentRoom->hasCharacter(npcName))
        {
            // get the npc object
            std::shared_ptr<NPC> npc = currentRoom->getNPC(npcName);
            // return the npc object dialogue
            std::cout << npc->getDialogue() << std::endl;
        }
        else
        {
            std::cout << npcName << " doesn't exist here." << std::endl;
        }
    }
    else
    {
        std::cout << "What do you mean?" << std::endl;
    }
}

void ZOOrkEngine::handleTakeCommand(std::vector<std::string> arguments)
{
    if (arguments.empty())
    {
        std::cout << "Take what?" << std::endl;
        return;
    }
    std::string itemName = arguments[0]; // Assuming single word item names for simplicity
    Room *currentRoom = player->getCurrentRoom();
    if (currentRoom->hasItem(itemName))
    {
        std::shared_ptr<Item> item = currentRoom->takeItem(itemName);
        Player::instance()->addItem(item);
        std::cout << "You took the " << itemName << "." << std::endl;
    }
    else
    {
        std::cout << "There is no " << itemName << " here." << std::endl;
    }
}

void ZOOrkEngine::handleInspectCommand(std::vector<std::string> arguments)
{
    if (arguments.empty())
    {
        std::cout << "Inspect what?" << std::endl;
        return;
    }
    std::string itemName = arguments[0]; // Assuming single word item names for simplicity
    if (player->hasItem(itemName))
    {
        std::shared_ptr<Item> item = player->getItem(itemName);
        std::cout << item->getDescription() << std::endl;
    }
    else
    {
        std::cout << "What is that? I can\'t find it in your inventory" << std::endl;
    }
}

void ZOOrkEngine::handleDropCommand(std::vector<std::string> arguments)
{
    if (arguments.empty())
    {
        std::cout << "Drop what?" << std::endl;
        return;
    }
    std::string itemName = arguments[0]; // Assuming single word item names for simplicity
    Room *currentRoom = Player::instance()->getCurrentRoom();
    if (Player::instance()->hasItem(itemName))
    {
        std::shared_ptr<Item> item = player->takeItem(itemName); // Use takeItem to get the item object
        currentRoom->addItem(item);
        std::cout << "You dropped the " << itemName << "." << std::endl;
    }
    else
    {
        std::cout << "You don't have a " << itemName << "." << std::endl;
    }
}

void ZOOrkEngine::handleQuitCommand(std::vector<std::string> arguments)
{
    std::string input;
    std::cout << "Are you sure you want to QUIT?\n> ";
    // std::cin >> input;
    std::getline(std::cin, input);
    std::string quitStr = makeLowercase(input);

    if (quitStr == "y" || quitStr == "yes")
    {
        std::cout << "See you next time..." << std::endl;
        gameOver = true;
    }
    else if(quitStr == "n" || quitStr == "no"){
        std::cout << "continuing..." << std::endl;
        return;
    }
    else{
        std::cout << "please enter valid response: yes / no" << std::endl;
        handleQuitCommand(arguments);
        // return;
    }
}

void ZOOrkEngine::handleHelpCommand()
{
    std::ifstream help("help.txt");

    if (help.is_open())
    {
        std::cout << help.rdbuf();
        help.close();
    }
    else
    {
        std::cerr << "Error: could not open file" << std::endl;
    }
}

void ZOOrkEngine::handleUseCommand(std::vector<std::string> arguments)
{
    if (arguments.size() < 2)
    {
        std::cout << "Use what on what?" << std::endl;
        return;
    }

    std::string itemName = arguments[0];
    std::string targetName = arguments[2];

    if (!player->hasItem(itemName))
    {
        std::cout << "You don't have a " << itemName << "!" << std::endl;
        return;
    }
    Room *currentRoom = player->getCurrentRoom();
    std::shared_ptr<NPC> npc = currentRoom->getNPC(targetName);

    if (npc)
    {
        if (npc->isDefeated())
        {
            std::cout << targetName << " is already defeated!" << std::endl;
        }
        else
        {
            player->interactWithNPC(npc, itemName);
            // player->removeItem(itemName);
        }
    }
    else
    {
        std::cout << "There is no " << targetName << " here." << std::endl;
    }
}

std::vector<std::string> ZOOrkEngine::tokenizeString(const std::string &input)
{
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ' '))
    {
        tokens.push_back(makeLowercase(token));
    }

    return tokens;
}

bool ZOOrkEngine::checkAllNPCsDefeated()
{
    for (const auto &npc : allNPCs)
    {
        if (!npc->isDefeated())
        {
            return false;
        }
    }
    return true;
}

std::string ZOOrkEngine::makeLowercase(std::string input)
{
    std::string output = std::move(input);
    std::transform(output.begin(), output.end(), output.begin(), ::tolower);

    return output;
}

void ZOOrkEngine::addNPC(std::shared_ptr<NPC> npc)
{
    allNPCs.push_back(npc);
}