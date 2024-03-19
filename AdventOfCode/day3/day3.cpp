#include <iostream>
#include <stdio.h>
#include <array>
#include <vector>
#include <fstream>
using namespace std;

int priority(string text)
{
    // calc length, init array
    int length = text.size();
    int strA[length / 2], strB[length / 2];
    int ascii[length];

    for (int i = 0; i < length; i++)
    {
        if ((int)text[i] > 93)
        {
            ascii[i] = (int)text[i] - 96;
        }
        else
        {
            ascii[i] = (int)text[i] - 38;
        }
        // cout << ascii[i] << " " << text[i] << endl;
    }

    for (int i = 0, j = length / 2; j < length; i++, j++)
    {
        strA[i] = ascii[i];
        strB[i] = ascii[j];
    }

    // print 2 array
    // for (int i = 0; i < length / 2; i++)
    // {
    //     cout << strA[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < length / 2; i++)
    // {
    //     cout << strB[i] << " ";
    // }

    for (int i = 0; i < length / 2; i++)
    {
        for (int j = 0; j < length / 2; j++)
        {
            if (strA[i] == strB[j])
            {
                // cout << endl << strA[i];
                return strA[i];
            }
        }
    }
}

int main()
{
    ifstream input("input.txt");
    vector<string> rucksacks;
    for (string line; getline(input, line);)
    {
        rucksacks.push_back(line);
    }
    int length = rucksacks.size();
    // for (int i = 0; i <= rucksacks.size(); i++)
    // {
    //     cout << rucksacks[i] << endl;
    // }
    int result[length];
    for (int i = 0; i <= length; i++)
    {
        result[i]=priority(rucksacks[i]);
    }
    // int result = priority("jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL");
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += result[i];
    }
    cout << "sum = " << sum << endl;
    return 0;
}