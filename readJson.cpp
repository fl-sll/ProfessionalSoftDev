#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include <fstream>
using namespace std;
using namespace rapidjson;
// source
// https://www.geeksforgeeks.org/rapidjson-file-read-write-in-cpp/
class Drink
{
public:
    string name;
    int sugar;
    int stock;
    void getDetails()
    {
        cout << name << " has " << sugar << " sugar. Stock = " << stock << endl;
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

void readMenu()
{
    // Open the file for reading
    FILE *fp = fopen("./Assessment2/files/data.json", "r");

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

    // Access the data in the JSON document
    std::cout << d["drink"][1]["name"].GetString() << std::endl;
    // std::cout << d["age"].GetInt() << std::endl;
}

int main()
{
    readMenu();
    // string name;
    // cout << "Enter patron name: ";
    // cin >> name;

    // Patron patron;
    // patron.name = name;
    // patron.getName();

    return 0;
}