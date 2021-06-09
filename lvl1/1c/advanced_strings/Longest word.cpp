#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>

using namespace std;

tuple<string, int> longestWord(string& input) {
    int maxlen = 0;
    string word, maxword;
    stringstream ss(input);
    while (ss >> word) {
        if (word.size() > maxlen) {
            maxword = word;
            maxlen = word.size();
        }
    }
    return make_tuple(maxword, maxlen);
}

int main() {
    string input;
    getline(cin, input);

    string maxword;
    int maxlen;
    tie(maxword, maxlen) = longestWord(input);
    cout << maxword << endl;
    cout << maxlen;
    return 0;
}