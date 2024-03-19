#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>

using namespace std;

vector<int> read_file(string s) {
    fstream content(s);
    vector<int> calorieCount;
    string line;
    int calories = 0;

    while(getline(content,line)) {
        if(line.empty()) {
            calorieCount.push_back(calories);
            calories = 0;
        }
        else {
            calories = calories + stoi(line);
        }
    }
    content.close();
    return calorieCount;
}

int max_calc(vector<int> elf) {
    int maxCalories = 0;
    int max2;
    int max3;

    for (int i = 0; i < elf.size(); i++) {
        if (elf[i] > maxCalories) {
            maxCalories = elf[i];
        }
    }
    return maxCalories;
}

int total(vector<int> elf) {
    int maxCalories = 0;
    int max2;
    int max3;
    for (int i = 0; i < elf.size(); i++) {
        if (elf[i] > maxCalories) {
            max3 = max2;
            max2 = maxCalories;
            maxCalories = elf[i];
        }
        else if (elf[i] > max2) {
            max3 = max2;
            max2 = elf[i];
        }
        else if (elf[i] > max3) {
            max3 = elf[i];
        }
    }
    int total = maxCalories + max2 + max3;
    cout << maxCalories << endl << max2 << endl << max3 << endl;
    return total;
}

int main() {
    string filename = "input.txt";
    vector<int> calorieCount = read_file(filename);
    int maxc = max_calc(calorieCount);
    
    cout << "Total calories carried by the Elf with the most calories " << maxc << endl;
    cout << "Total of top 3 elves are " << total(calorieCount) << endl;
};