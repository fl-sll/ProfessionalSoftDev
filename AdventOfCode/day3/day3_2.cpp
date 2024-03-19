#include <iostream>
#include <stdio.h>
#include <array>
#include <vector>
#include <fstream>
using namespace std;

int search(string text[2])
{
    for (int i = 0; i < text[0].length(); i++)
    {
        for (int j = 0; j < text[1].length(); j++)
        {
            for (int k = 0; k < text[2].length(); k++)
            {
                if (text[0][i] == text[1][j] && text[0][i] == text[2][k])
                {
                    return text[0][i];
                }
            }
        }
    }
}
int main()
{
    ifstream input("input.txt");
    vector<string> rucksacks;
    string mini[2];
    for (string line; getline(input, line);)
    {
        rucksacks.push_back(line);
    }
    int length = rucksacks.size();
    cout << length << endl;

    vector<int> result;

    for (int i = 0, j = 0; i < length; i++, j++)
    {
        if (j == 2)
        {
            mini[j] = rucksacks[i];

            if (search(mini) > 93)
            {
                cout << search(mini) - 96 << endl;
                result.push_back(search(mini)-96);
            }
            else{
                cout << search(mini) - 38 << endl;
                result.push_back(search(mini)-38);
            }

            j = -1;
            cout << "----" << endl;
        }
        else
        {
            mini[j] = rucksacks[i];
        }
    }
    int final = 0;
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
        final += result[i];
    }
    cout << final << endl;
}