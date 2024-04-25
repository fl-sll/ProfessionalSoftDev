#ifndef READ_H
#define READ_H

#include <iostream>
// #include "./../rapidjson/include/rapidjson/document.h"
// #include "./../rapidjson/include/rapidjson/filereadstream.h"
#include "./coffee.h"
#include "./food.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
using namespace rapidjson;
// source
// https://www.geeksforgeeks.org/rapidjson-file-read-write-in-cpp/
// class Drink
// {
//     string name;
//     int sugar;
//     int stock;

// public:
//     Drink(string name, int sugar, int stock)
//     {
//         this->name = name;
//         this->sugar = sugar;
//         this->stock = stock;
//     }
//     string getDetails()
//     {
// stringstream ss;
// ss << name << " has " << sugar << " sugar. Stock = " << stock;
// return ss.str();
//     }
// };

// class Food
// {
//     string name;
//     int stock;

// public:
//     Food(string name, int stock)
//     {
//         this->name = name;
//         this->stock = stock;
//     }
//     string getDetails()
//     {
//         stringstream ss;
//         ss << name << ". Stock = " << stock;
//         return ss.str();
//     }
// };

pair<vector<Coffee>, vector<Food> > readMenu()
{
    // cout << "making drinks" << endl;
    // Open the file for reading
    FILE *fp = fopen("./Assessment2/files/data.json", "r");

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

    vector<Coffee> drinkVector;

    rapidjson::Value::ConstValueIterator itr;

    for (itr = d["drink"].Begin(); itr != d["drink"].End(); ++itr)
    {
        // Drink* drink = new Drink();
        string name = itr->GetObject()["name"].GetString();
        int sugar = itr->GetObject()["sugar"].GetInt();
        int stock = itr->GetObject()["stock"].GetInt();
        Coffee coffee = Coffee(name);
        coffee.addSugar(sugar);
        coffee.addStock(stock);
        drinkVector.push_back(coffee);
    }

    vector<Food> foodVector;
    for (itr = d["food"].Begin(); itr != d["food"].End(); ++itr)
    {
        // Drink* drink = new Drink();
        string name = itr->GetObject()["name"].GetString();
        int stock = itr->GetObject()["stock"].GetInt();
        Food food = Food(name);
        food.addStock(stock);
        foodVector.push_back(food);
    }

    return make_pair(drinkVector, foodVector);
}

// int main()
// {
// pair<vector<Drink>, vector<Food>> r = readMenu();
// vector<Drink> drinkvector = r.first;
// vector<Food> foodvector = r.second;

// for (int i = 0; i < foodvector.size(); ++i)
// {
//     cout << foodvector[i].getDetails() << endl;
// }

// for (int i = 0; i < drinkvector.size(); ++i)
// {
//     cout << drinkvector[i].getDetails() << endl;
// }

//     cout << typeid(r).name() << endl;

//     return 0;
// }

#endif