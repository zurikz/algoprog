#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string decrypt(const string& encrypted) {
    int len = encrypted.size() - 1;
    string decrypted(len, ' ');
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            decrypted[i / 2] = encrypted[i];
        } else {
            decrypted[(len - 1) - (i / 2)] = encrypted[i];
        }
    }
    return decrypted;
}

int main() {
    string input;
    cin >> input;
    cout << decrypt(input);
    return 0;
}