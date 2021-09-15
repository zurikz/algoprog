#include <iostream>
#include <vector>
#include <string>

using namespace std;

int classify(const char& ch) {
    if (ch == ';' || ch == ':') {
        return 0;
    }
    if (ch == '-') {
        return 1;
    }
    if (ch == '(' || ch == ')' || ch == '[' || ch == ']') {
        return 2;
    }
    return 3;
}

int countSmiles(const string& input) {
    int count = 0;
    vector<int> state = {0, 0, 0, 0};
    for (const char& ch : input) {
        ++state[classify(ch)];
        if (state[0] > 1) {
            state = {1, 0, 0, 0};
        } else if (state[3] > 0) {
            state = {0, 0, 0, 0};
        } else if (state[0] == 1 && state[2] == 0) {
            continue;
        } else if (state[0] == 1 && state[2] == 1) {
            ++count;
            state = {0, 0, 0, 0};
        } else {
            state = {0, 0, 0, 0};
        }
    }
    return count;
}

int main() {
    string input;
    getline(cin, input);
    cout << countSmiles(input);
    return 0;
}