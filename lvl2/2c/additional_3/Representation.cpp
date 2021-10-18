#include <iostream>
#include <fstream>

using namespace std;

pair<int, int> solve(int n) {
    int a = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            a = i;
            break;
        }
    }
    int b = n / a;
    return {b, n - b};
}

/****** testing ******/

const bool TEST = 0;

int test(ifstream& file) {
    int testNum = 1;
    while (file) {
        int n;
        file >> n;
        pair<int, int> answer;
        file >> answer.first >> answer.second;
        file.ignore(2);
        auto solution = solve(n);
        if (solution != answer) {
            cout << "Failed test no. " << testNum << endl;
            cout << n << '\n' << "Answer: " << answer.first << " " << answer.second << '\n';
            cout << "Solution: " << solution.first << " " << solution.second << endl;
            return 1;
        }
        ++testNum;
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("Representation.txt");
        test(file);
    } else {
        int n;
        cin >> n;
        auto solution = solve(n);
        cout << solution.first << " " << solution.second;
    }
    return 0;
}