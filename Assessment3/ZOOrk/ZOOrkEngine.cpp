//
// Created by Richard Skarbez on 5/7/23.
//

#include "ZOOrkEngine.h"

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
// TODO change this to something global
// #include "../../../../../../msys64/mingw64/include/c++/11.2.0/bits/algorithmfwd.h"

ZOOrkEngine::ZOOrkEngine(std::shared_ptr<Room> start)
{
    player = Player::instance();
    player->setCurrentRoom(start.get());
    player->getCurrentRoom()->enter();
}

void ZOOrkEngine::run()
{
    while (!gameOver)
    {
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
        else if ((command == "look") || (command == "inspect"))
        {
            handleLookCommand(arguments);
        }
        else if ((command == "take") || (command == "get"))
        {
            handleTakeCommand(arguments);
        }
        else if (command == "drop")
        {
            handleDropCommand(arguments);
        }
        else if (command == "quit")
        {
            handleQuitCommand(arguments);
        }
        else if (command == "inventory")
        {
            player->showInventory();
        }
        else if (command == "help")
        {
            // TODO create a help function to print the list of hints (word hints)
            handleHelpCommand();
        }
        else
        {
            std::cout << "I don't understand that command.\n";
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
    else if (arguments[0] == "u" || arguments[0] == "up")
    {
        direction = "up";
    }
    else if (arguments[0] == "d" || arguments[0] == "down")
    {
        direction = "down";
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
    // To be implemented
    // if (arguments.empty())
    // {
    //     std::cout << "Look at what?" << std::endl;
    //     return;
    // }
    Room *currentRoom = player->getCurrentRoom();
    std::cout << "You are currently in " << currentRoom->getName() << std::endl;
    std::cout << currentRoom->getDescription() << std::endl;
    currentRoom->getItem();
    currentRoom->getCharacter();

    // std::cout << "This functionality is not yet enabled.\n";
}

void ZOOrkEngine::handleTakeCommand(std::vector<std::string> arguments)
{
    // To be implemented
    if (arguments.empty())
    {
        std::cout << "Take what?" << std::endl;
        return;
    }

    std::string itemName = arguments[0]; // Assuming single word item names for simplicity
    Room *currentRoom = player->getCurrentRoom();
    std::cout << itemName << std::endl;
    if (currentRoom->hasItem(itemName))
    {
        std::shared_ptr<Item> item = currentRoom->takeItem(itemName);
        Player::instance()->addItem(item);
        // currentRoom -> removeItem(itemName);
        std::cout << "You took the " << itemName << "." << std::endl;
    }
    else
    {
        std::cout << "There is no " << itemName << " here." << std::endl;
    }
    // std::cout << "This functionality is not yet enabled.\n";
}

void ZOOrkEngine::handleDropCommand(std::vector<std::string> arguments)
{
    // To be implemented
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
        // Player::instance()->takeItem(itemName);
        currentRoom->addItem(item);
        std::cout << "You dropped the " << itemName << "." << std::endl;
    }
    else
    {
        std::cout << "You don't have a " << itemName << "." << std::endl;
    }
    // std::cout << "This functionality is not yet enabled.\n";
}

void ZOOrkEngine::handleQuitCommand(std::vector<std::string> arguments)
{
    std::string input;
    std::cout << "Are you sure you want to QUIT?\n> ";
    std::cin >> input;
    std::string quitStr = makeLowercase(input);

    if (quitStr == "y" || quitStr == "yes")
    {
        gameOver = true;
    }
}

void ZOOrkEngine::handleHelpCommand()
{
    std::ifstream help("../help.txt");

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

std::string ZOOrkEngine::makeLowercase(std::string input)
{
    std::string output = std::move(input);
    std::transform(output.begin(), output.end(), output.begin(), ::tolower);

    return output;
}