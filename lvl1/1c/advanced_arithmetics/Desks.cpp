#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int solution(const vector<int>& classes) {
    int desks = 0;
    for (const int& students : classes) {
        desks += (students / 2) + (students % 2);
    }
    return desks;
}

void readTest(ifstream& input, vector<int>& classes, int& answer) {
    if (input.is_open()) {
        string line;
        getline(input, line);
        input >> classes[0] >> classes[1] >> classes[2];
        getline(input, line);
        getline(input, line);
        input >> answer;
        getline(input, line);
        getline(input, line);
    }
}

int test(ifstream& input) {
    while (input) {
        int answer;
        vector<int> classes(3);
        readTest(input, classes, answer);
        if (solution(classes) != answer) {
            cout << "Failed test:" << endl;
            for (const int& students : classes) {
                cout << students << " ";
            }
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    vector<int> classes(3);
    cin >> classes[0] >> classes[1] >> classes[2];
    cout << solution(classes);
    return 0;
}