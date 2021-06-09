#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string word;
    map<char, int> char2freq;
    while (cin >> word) {
        for (const char& ch : word) {
            ++char2freq[ch];
            if (char2freq[ch] == 2) {
                cout << ch;
                return 0;
            }
        }
    }
    return 0;
}