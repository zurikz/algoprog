#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void reverseWord(string& word) {
    int len = word.length();
    for (int i = 0; i < len / 2; i++) {
        char tmp = word[i];
        word[i] = word[(len - 1) - i];
        word[(len - 1) - i] = tmp;
    }
}

vector<string> reverse(const vector<string>& text) {
    vector<string> reversed;
    for (const string& line : text) {
        string word, reversedLine;
        for (const char& ch : line) {
            if (isalpha(ch)) {
                word += ch;
            } else {
                reverseWord(word);
                reversedLine += word;
                word = "";
                reversedLine += ch;
            }
        }
        reverseWord(word);
        reversedLine += word;
        reversed.push_back(reversedLine);
    }
    return reversed;
}

int main() {
    vector<string> text;
    string line;
    while (getline(cin, line)) {
        text.push_back(line);
    }

    vector<string> reversedText = reverse(text);
    for (const string& line : reversedText) {
        cout << line << endl;
    }
    return 0;
}