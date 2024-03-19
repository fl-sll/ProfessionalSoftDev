#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <string>
#include <array>
#include <map>
#include <fstream>

using namespace std;

vector<string> read_file(string s) {
    vector<string> games;
    fstream content(s);
    string line;
    
    while(getline(content, line)) {
        games.push_back(line);
    }
    content.close();
    return games;
}

int calculate_score(vector<string> game) {
    int lose = 0;
    int draw = 3;
    int win = 6;
    int rock = 1;
    int paper = 2;
    int scissor = 3;
    int score;

    for (int i = 0; i < game.size(); i++) {
        if (game[i][0] == 'A') {
            if (game[i][2] == 'X') {
                score += draw + rock;
            }
            else if (game[i][2]== 'Y') {
                score += win + paper;
            }
            else if (game[i][2]== 'Z') {
                score += lose + scissor;
            }
        }
        else if (game[i][0] == 'B') {
            if (game[i][2]== 'X') {
                score += lose + rock;
            }
            else if (game[i][2]== 'Y') {
                score += draw + paper;
            }
            else if (game[i][2]== 'Z') {
                score += win + scissor;
            }
        }
        else if (game[i][0] == 'C') {
            if (game[i][2]== 'X') {
                score += win + rock;
            }
            else if (game[i][2]== 'Y') {
                score += lose + paper;
            }
            else if (game[i][2]== 'Z') {
                score += draw + scissor;
            }
        }
    }
    return score;
}

int calculate_w(vector<string> game) {
    int lose = 0;
    int draw = 3;
    int win = 6;
    int rock = 1;
    int paper = 2;
    int scissor = 3;
    int score;

    for (int i = 0; i < game.size(); i++) {
        if (game[i][0] == 'A') {
            if (game[i][2] == 'X') {
                score += lose + scissor;
            }
            else if (game[i][2] == 'Y') {
                score += draw + rock;
            }
            else if (game[i][2] == 'Z') {
                score += win + paper;
            }
        }
        else if (game[i][0] == 'B') {
            if (game[i][2] == 'X') {
                score += lose + rock;
            }
            else if (game[i][2] == 'Y') {
                score += draw + paper;
            }
            else if (game[i][2] == 'Z') {
                score += win + scissor;
            }
        }
        else if (game[i][0] == 'C') {
            if (game[i][2] == 'X') {
                score += lose + paper;
            }
            else if (game[i][2] == 'Y') {
                score += draw + scissor;
            }
            else if (game[i][2] == 'Z') {
                score += win + rock;
            }
        }
    }
    return score;
}


int main() {
    string filename = "input.txt";
    vector<string> game = read_file(filename);
    int score = calculate_score(game);
    int wscore = calculate_w(game);

    cout << score << endl;
    cout << wscore << endl;
}
