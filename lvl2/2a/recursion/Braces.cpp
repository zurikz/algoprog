#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

string bracefy(const string& str) {
    int len = str.length();
    if (len < 3) {
        return str;
    } else {
        string substring = str.substr(1, len - 2);
        return string(1, str[0]) + "(" + bracefy(substring) + ")" + string(1, str[len - 1]);
    }
}

int main() {
    string input;
    cin >> input;
    cout << bracefy(input);
    return 0;
}