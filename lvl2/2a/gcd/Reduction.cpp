#include <iostream>
#include <fstream>
#include <utility>
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

pair<int, int> reduceFraction(int numer, int denom) {
    int g = gcd(abs(numer), denom);
    return make_pair(numer / g, denom / g);
}

/****** testing ******/

void readTest(ifstream& file, int& a, int& b, int& c, int& d) {
    string line;
    getline(file, line);
    file >> a >> b >> c >> d;
    file.ignore();
    getline(file, line);
}

int test(ifstream& file) {
    while (file) {
        int a, b, c, d;
        readTest(file, a, b, c, d);
        pair<int, int> s = reduceFraction(a, b);
        if (s.first != c  || s.second != d) {
            cout << "Failed test!" << endl;
            cout << "Input: " << a << " " << b << endl;
            cout << "Answer: " << c << " " << d << endl;
            cout << "My answer: " << s.first << " " << s.second << endl;
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("Reduction.txt");
        test(file);
    } else {
        int a, b;
        cin >> a >> b;
        pair<int, int> r = reduceFraction(a, b);
        cout << r.first << " " << r.second;
    }
    return 0;
}