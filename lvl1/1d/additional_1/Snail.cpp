#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int solve(int h, int a, int b) {
    int step = a - b;
    int d = (h - b - 1) / step;
    return 1 + d;
}

void readTest(ifstream& file, int& h, int& a, int& b, int& answer) {
    string line;
    getline(file, line);
    file >> h >> a >> b;
    file.ignore();
    getline(file, line);
    file >> answer;
    file.ignore();
    getline(file, line);
}

int test(ifstream& file) {
    while (file) {
        int h, a, b, answer;
        readTest(file, h, a, b, answer);
        int solution = solve(h, a, b);
        if (solution != answer) {
            cout << "Input: " << h << " " << a << " " << b << endl;
            cout << "Answer: " << answer << endl;
            cout << "My answer: " << solution << endl;
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    int h, a, b;
    cin >> h >> a >> b;
    cout << solve(h, a, b);
    return 0;
}