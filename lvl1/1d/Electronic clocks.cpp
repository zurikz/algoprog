#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string solve(int seconds) {
    string answer;
    int hrs = (seconds / (60 * 60)) % 24;
    answer += to_string(hrs) + ':';
    int mins = (seconds - hrs * 60 * 60) / 60;
    answer += to_string(mins / 10) + to_string(mins) + ':';
    int secs = seconds - hrs * 60 * 60 - mins * 60;
    answer += to_string(secs / 10) + to_string(secs);
    return answer;
}

void readTest(ifstream& file, int& seconds, string& answer) {
    if (file.is_open()) {
        string line;
        getline(file, line);
        file >> seconds;
        file.ignore();
        getline(file, line);
        getline(file, answer);
        getline(file, line);
    }
}

int test(ifstream& file) {
    while (file) {
        int seconds;
        string answer;
        readTest(file, seconds, answer);
        string solution = solve(seconds);
        if (solution != answer) {
            cout << "Input: " << seconds << endl;
            cout << "Answer: " << answer << endl;
            cout << "My answer: " << solution;
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    ifstream file("Electronic clocks.txt");
    test(file);
    return 0;
}