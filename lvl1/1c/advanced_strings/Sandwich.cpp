#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string decrypt(const string& encrypted) {
    int len = encrypted.size() - 1;
    char decrypted[len];
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            decrypted[i / 2] = encrypted[i];
        } else {
            decrypted[(len - 1) - (i / 2)] = encrypted[i];
        }
    }
    return string(decrypted);
}

void readTest(ifstream& file, string& encrypted, string& answer) {
    if (file.is_open()) {
        string line;
        getline(file, line);
        getline(file, encrypted);
        getline(file, line);
        getline(file, answer);
        getline(file, line);
    }
}

int test(ifstream& file) {
    while (file) {
        string encrypted, answer;
        readTest(file, encrypted, answer);
        string decrypted = decrypt(encrypted);
        if (decrypted != answer) {
            cout << "Failed test:" << endl;
            cout << encrypted << endl;
            cout << "Answer:    " << answer << endl;
            cout << "My answer: " << decrypted << endl;
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    // ifstream file("Sandwich.txt");
    // test(file);
    string input;
    cin >> input;
    cout << decrypt(input);
    return 0;
}