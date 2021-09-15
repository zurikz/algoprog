#include <iostream>
#include <string>

using namespace std;

string solve(const string& input) {
    string number;
    for (size_t i = 0; i < input.size(); i++) {
        if (isdigit(input[i])) {
            number += input[i];
            if (stoi(number) > 5) {
                return "NO";
            }
        } else {
            number = "";
        }
    }
    return "YES";
}

int main() {
    string input;
    cin >> input;
    cout << solve(input);
    return 0;
}