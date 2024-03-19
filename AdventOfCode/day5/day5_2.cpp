#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

#define MAX_NUM_STACKS 9

#define COLUMN_WIDTH 4

inline bool is_line_for_crates(const string &line) {
    return line.find('[') != string::npos;
}

int main(int argc, char *argv[])
{
    ifstream input("input.txt");
    string line;
    deque<char> stacks[MAX_NUM_STACKS];
    deque<char> crane;
    unsigned num_stacks = 0;
    bool stacks_are_parsed = false;

    while (getline(input, line)) {
        if (!stacks_are_parsed) {
            if (line.length() == 0) {
                stacks_are_parsed = true;
                continue;
            }
            if (is_line_for_crates(line)) {
                for (unsigned i = 1; i < line.length(); i += COLUMN_WIDTH) {
                    if (line[i] != ' '){
                        stacks[i / COLUMN_WIDTH].push_back(line[i]);
                    }
                }
            } 
            else {
                for (char c: line) {
                    if (c != ' ') num_stacks++;
                }
            }
        } 
        else {
            stringstream ss(line);

            unsigned num_moved = 0;
            unsigned stack_num = 0;

            char dummy[5];
            ss.read(dummy, 5);
            ss >> num_moved;
            ss.read(dummy, 5);
            ss >> stack_num; 
            stack_num -= 1;

            for (unsigned i = 0; i < num_moved; i++) {
                crane.push_back(stacks[stack_num].front());
                stacks[stack_num].pop_front();
            }

            ss.read(dummy, 3);
            ss >> stack_num; 
            stack_num -= 1;

            while(!crane.empty()) {
                stacks[stack_num].push_front(crane.back());
                crane.pop_back();
            }
        }
    }

    for (unsigned i = 0; i < num_stacks; i++) {
        cout << stacks[i].front();
    }

    cout << endl;
    input.close();
    
}