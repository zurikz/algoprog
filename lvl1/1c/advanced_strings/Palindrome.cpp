#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    string line = "";
    for (const auto& ch : input) {
        if (ch != ' ') {
            line += ch;
        }
    }

    for (int i = 0; i < line.size() / 2; i++) {
        if (line[i] != line[line.size() - 1 - i]) {
            cout << "no";
            return 0;
        }
    }
    cout << "yes";
    return 0;
}