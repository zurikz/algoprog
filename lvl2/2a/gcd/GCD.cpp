#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const bool TEST = 0;

int gcd(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

/****** testing ******/

void readTest(ifstream& file, int& a, int& b, int& answer) {
    string line;
    getline(file, line);
    file >> a >> b >> answer;
    file.ignore();
    getline(file, line);
}

int test(ifstream& file) {
    while (file) {
        int a, b, answer;
        readTest(file, a, b, answer);
        int solution = gcd(a, b);
        if (solution != answer) {
            cout << "Failed test!" << endl;
            cout << "Input: " << a << " " << b << endl;
            cout << "Answer: " << answer << endl;
            cout << "My answer: " << solution << endl;
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("GCD.txt");
        test(file);
    } else {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b);
    }
    return 0;
}