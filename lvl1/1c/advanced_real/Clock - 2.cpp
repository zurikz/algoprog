#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

double solve(double alpha) {
    return 12.0 * (alpha - (30 * (int(alpha) / 30)));
}

void readTest(ifstream& file, double& input, double& answer) {
    if (file.is_open()) {
        string line;
        getline(file, line);
        file >> input;
        file.ignore();
        getline(file, line);
        file >> answer;
        file.ignore();
        getline(file, line);
    }
}

int test(ifstream& file) {
    while (file) {
        double input, answer;
        readTest(file, input, answer);
        double solution = solve(input);
        if (solution != answer) {
            cout << "Failed test:" << endl;
            cout << "Input: " << input << endl;
            cout << "Answer: " << answer << endl;
            cout << "My answer: " << solution;
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    double alpha;
    cin >> alpha;
    cout << solve(alpha);
    return 0;
}