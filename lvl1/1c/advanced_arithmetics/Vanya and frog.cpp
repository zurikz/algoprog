#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int solution(const int& bound, const int& sec) {
    return -abs((sec % (2 * bound) - bound)) + bound;
}

void readTest(ifstream& file, int& bound, int& sec, int& answer) {
    if (file.is_open()) {
        string line;
        getline(file, line);
        file >> bound >> sec;
        getline(file, line);
        getline(file, line);
        file >> answer;
        getline(file, line);
        getline(file, line);
    }
}

int test(ifstream& file) {
    while (file) {
        int bound, sec, answer;
        readTest(file, bound, sec, answer);
        if (solution(bound, sec) != answer) {
            cout << "Failed test:" << endl;
            cout << "  Input: " << bound << " " << sec << endl;
            cout << "  Answer: " << answer << endl;
            cout << "  My answer: " << solution(bound, sec);
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    ifstream file("Vanya and frog.txt");
    test(file);
    return 0;
}