#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

const vector<char> nonAlphas = {
    ' ', '.', '!', '?', ':', '-', ',', ';', '(', ')'
};

bool isAlpha(const char& ch) {
    for (const char& nonAlpha : nonAlphas) {
        if (ch == nonAlpha) {
            return false;
        }
    }
    return true;
}

vector<string> split(const string& line) {
    vector<string> words;
    string word;
    for (const char& ch : line) {
        if (isAlpha(ch)) {
            word += ch;
        } else {
            if (!word.empty()) {
                words.push_back(word);
            }
            word = "";
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}

bool isWordSuspicious(const string& word) {
    set<char> letters;
    for (const char& ch : word) {
        letters.insert(ch);
    }
    if (letters.size() > 3) {
        return false;
    }
    return true;
}

bool isLineSuspicious(const string& line) {
    vector<string> words = split(line);
    int suspiciousWords = 0;
    for (const string& word : words) {
        if (isWordSuspicious(word)) {
            ++suspiciousWords;
        }
    }
    if (suspiciousWords >= (double) words.size() / 2) {
        return true;
    }
    return false;
}

void censor() {
    string line;
    while (getline(cin, line)) {
        if (isLineSuspicious(line)) {
            continue;
        } else {
            cout << line << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    censor();
    return 0;
}