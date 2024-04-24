#include <iostream>
#include "./rapidjson/include/rapidjson/document.h"
#include "./rapidjson/include/rapidjson/filereadstream.h"
// #include "rapidjson/document.h"
// #include "rapidjson/filereadstream.h"
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
using namespace rapidjson;
// source
// https://www.geeksforgeeks.org/rapidjson-file-read-write-in-cpp/
class Drink
{
    string name;
    int sugar;
    int stock;

public:
    Drink(string name, int sugar, int stock)
    {
        this->name = name;
        this->sugar = sugar;
        this->stock = stock;
    }
    string getDetails()
    {
        stringstream ss;
        ss << name << " has " << sugar << " sugar. Stock = " << stock;
        return ss.str();
    }
};

class Food
{
    string name;
    int stock;

public:
    Food(string name, int stock)
    {
        this->name = name;
        this->stock = stock;
    }
    string getDetails()
    {
        stringstream ss;
        ss << name << ". Stock = " << stock;
        return ss.str();
    }
};
class Patron
{
public:
    string name;
    void getName()
    {
        cout << name << endl;
    };
};

class FoodMaker{
    public:

};

class Manager
{
public:
    // Manger();
    void informFood(Food food){
        FoodMaker foodMaker;

    };
    void informDrink(Drink drink);
};

class Host
{
public:
    // Host();
    void informManager(Drink drink, Food food)
    {
        Manager manager;
        manager.informDrink(drink);
        manager.informFood(food);

    }
};

pair< vector<Drink>, vector<Food> > readMenu()
{
    cout << "making drinks" << endl;
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

    vector<Drink> drinkVector;

    rapidjson::Value::ConstValueIterator itr;

    for (itr = d["drink"].Begin(); itr != d["drink"].End(); ++itr)
    {
        // Drink* drink = new Drink();
        string name = itr->GetObject()["name"].GetString();
        int sugar = itr->GetObject()["sugar"].GetInt();
        int stock = itr->GetObject()["stock"].GetInt();
        drinkVector.push_back(Drink(name, sugar, stock));
    }
    // for (int i = 0; i < drinkVector.size(); ++i)
    // {
    //     cout << drinkVector[i].getDetails() << endl;
    // }

    vector<Food> foodVector;
    for (itr = d["food"].Begin(); itr != d["food"].End(); ++itr)
    {
        // Drink* drink = new Drink();
        string name = itr->GetObject()["name"].GetString();
        int stock = itr->GetObject()["stock"].GetInt();
        foodVector.push_back(Food(name, stock));
    }
    // for (int i = 0; i < foodVector.size(); ++i)
    // {
    //     cout << foodVector[i].getDetails() << endl;
    // }

    return make_pair(drinkVector, foodVector);
}

int main()
{
    pair< vector<Drink>, vector<Food> > r = readMenu();
    vector<Drink> drinkvector = r.first;
    vector<Food> foodvector = r.second;

    for (int i = 0; i < foodvector.size(); ++i)
    {
        cout << foodvector[i].getDetails() << endl;
    }

    for (int i = 0; i < drinkvector.size(); ++i)
    {
        cout << drinkvector[i].getDetails() << endl;
    }
    
    // string name;
    // cout << "Enter patron name: ";
    // cin >> name;

    // Patron patron;
    // patron.name = name;
    // patron.getName();

    cout << typeid(r).name() << endl;

    return 0;
}