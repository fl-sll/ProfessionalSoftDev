#ifndef READ_H
#define READ_H

#include <iostream>
#include "./../../../rapidjson-master/include/rapidjson/document.h"
#include "./../../../rapidjson-master/include/rapidjson/filereadstream.h"
#include "./../../../rapidjson-master/include/rapidjson/filewritestream.h"
#include "./../../../rapidjson-master/include/rapidjson/prettywriter.h"
#include "./coffee.h"
#include "./food.h"
// #include "rapidjson/document.h"
// #include "rapidjson/filereadstream.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace rapidjson;

// source
// https://www.geeksforgeeks.org/rapidjson-file-read-write-in-cpp/

inline std::pair<std::vector<Coffee>, std::vector<Food>> readMenu()
{
    // Open the file for reading
    FILE *fp = fopen("./../files/data.json", "r");

    // Use a FileReadStream to
    // read the data from the file
    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));

    // Parse the JSON data
    // using a Document object
    rapidjson::Document d;
    d.ParseStream(is);

    // Close the file
    fclose(fp);

    std::vector<Coffee> drinkVector;

    rapidjson::Value::ConstValueIterator itr;

    for (itr = d["drink"].Begin(); itr != d["drink"].End(); ++itr) {
        std::string name = itr->GetObject()["name"].GetString();
        int sugar = itr->GetObject()["sugar"].GetInt();
        int stock = itr->GetObject()["stock"].GetInt();
        Coffee coffee = Coffee(name, sugar, stock);
        drinkVector.push_back(coffee);
    }

    std::vector<Food> foodVector;
    for (itr = d["food"].Begin(); itr != d["food"].End(); ++itr) {
        // Drink* drink = new Drink();
        std::string name = itr->GetObject()["name"].GetString();
        int stock = itr->GetObject()["stock"].GetInt();
        Food food = Food(name, stock);
        foodVector.push_back(food);
    }

    return make_pair(drinkVector, foodVector);
}

inline void updateJsonDrink(std::vector<Coffee> drink, std::string name) {
    FILE *fp = fopen("./../files/data.json", "r");

    // Use a FileReadStream to
    // read the data from the file
    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));

    // Parse the JSON data
    // using a Document object
    rapidjson::Document d;
    d.ParseStream(is);

    // Close the file
    fclose(fp);

    for (int i = 0; i < drink.size(); i++) {
        if (d["drink"][i]["name"].GetString() == name) {
            Value &stock = d["drink"][i]["stock"];
            stock.SetInt(drink[i].getStock() - 1);
            break;
        }
        else {
            continue;
        }
    }

    fp = fopen("./../files/data.json", "w");

    // Use a FileReadStream to
    // read the data from the file
    char writeBuffer[65536];
    FileWriteStream os(fp, writeBuffer,
                       sizeof(writeBuffer));

    PrettyWriter<FileWriteStream> writer(os);
    d.Accept(writer);
    fclose(fp);
}

inline void updateJsonFood(std::vector<Food> food, std::string name) {
    FILE *fp = fopen("./../files/data.json", "r");

    // Use a FileReadStream to
    // read the data from the file
    char readBuffer[65536];
    rapidjson::FileReadStream is(fp, readBuffer,
                                 sizeof(readBuffer));

    // Parse the JSON data
    // using a Document object
    rapidjson::Document d;
    d.ParseStream(is);

    // Close the file
    fclose(fp);

    for (int i = 0; i < food.size(); i++)
    {
        if (d["food"][i]["name"].GetString() == name)
        {
            Value &stock = d["food"][i]["stock"];
            stock.SetInt(food[i].getStock() - 1);
            break;
        }
        else
        {
            continue;
        }
    }

    fp = fopen("./../files/data.json", "w");

    // Use a FileWriteStream to
    // write the data from the file
    char writeBuffer[65536];
    FileWriteStream os(fp, writeBuffer,
                       sizeof(writeBuffer));

    PrettyWriter<FileWriteStream> writer(os);
    d.Accept(writer);
    fclose(fp);
}

#endif