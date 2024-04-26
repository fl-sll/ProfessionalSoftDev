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
// using namespace std;
using namespace rapidjson;
// source
// https://www.geeksforgeeks.org/rapidjson-file-read-write-in-cpp/

std::pair<std::vector<Coffee>, std::vector<Food>> readMenu()
{
    // cout << "making drinks" << endl;
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

    for (itr = d["drink"].Begin(); itr != d["drink"].End(); ++itr)
    {
        // Drink* drink = new Drink();
        std::string name = itr->GetObject()["name"].GetString();
        int sugar = itr->GetObject()["sugar"].GetInt();
        int stock = itr->GetObject()["stock"].GetInt();
        Coffee coffee = Coffee(name, sugar, stock);
        coffee.addSugar(sugar);
        coffee.addStock(stock);
        drinkVector.push_back(coffee);
    }

    std::vector<Food> foodVector;
    for (itr = d["food"].Begin(); itr != d["food"].End(); ++itr)
    {
        // Drink* drink = new Drink();
        std::string name = itr->GetObject()["name"].GetString();
        int stock = itr->GetObject()["stock"].GetInt();
        Food food = Food(name, stock);
        food.addStock(stock);
        foodVector.push_back(food);
    }

    return make_pair(drinkVector, foodVector);
}

void updateJsonDrink(std::vector<Coffee> drink, int i)
{
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

    Value &stock = d["drink"][i]["stock"];
    stock.SetInt(drink[i].getStock() - 1);

    fp = fopen("./../files/data.json", "w");

    // Use a FileWriteStream to
    // write the data from the file
    char writeBuffer[65536];
    FileWriteStream os(fp, writeBuffer,
                       sizeof(writeBuffer));

    PrettyWriter<FileWriteStream> writer(os);
    d.Accept(writer);
    fclose(fp);
    std::cout<< "updated" << drink[i].getDetails()<< std::endl;
}

void updateJsonFood(std::vector<Food> food, int i)
{
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

    Value &stock = d["food"][i]["stock"];
    stock.SetInt(food[i].getStock() - 1);

    // cout << drink.getName() << endl;

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