#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int solve(const vector<int>& money) {
    int currentFives = 0;
    int answer = 0;
    for (const int& x : money) {
        if (x == 5) {
            ++currentFives;
        } else {
            int requiredFives = (x - 5) / 5;
            if (requiredFives > currentFives) {
                answer += requiredFives - currentFives;
                currentFives = 0;
            } else {
                currentFives -= requiredFives;
            }
        }
    }
    return answer;
}

/********* testing **********/

tuple<vector<int>, int> readTest(ifstream& file) {
    string line;
    getline(file, line);
    int n;
    file >> n;
    vector<int> input(n);
    for (int& x : input) {
        file >> x;
    }
    file.ignore();
    getline(file, line);
    int answer;
    file >> answer;
    file.ignore();
    getline(file, line);
    return tie(input, answer);
}

int test(ifstream& file) {
    while (file) {
        auto [input, answer] = readTest(file);
        int solution = solve(input);
        if (solution != answer) {
            cout << "Failed test!" << endl;
            for (const int& x : input) {
                cout << x << " ";
            }
            cout << endl;
            cout << "Answer: " << answer << endl;
            cout << "My answer: " << solution << endl;
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    // ifstream file("Change.txt");
    // test(file);
    int n;
    cin >> n;
    vector<int> money(n);
    for (int& x : money) {
        cin >> x;
    }
    cout << solve(money);
    return 0;
}