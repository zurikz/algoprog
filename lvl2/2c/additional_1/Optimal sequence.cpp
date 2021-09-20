#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int solve(int n) {
    vector<vector<int>> a(n + 1, vector<int> (n + 1, 0));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (i == 1 && j == 1) continue;
            int number = stoi(to_string(i) + to_string(j));
            a[i][j] = max(a[i - 1][j], a[i][j - 1]) + isPrime(number);
        }
    }
    return a[n][n];
}

/****** tesing ******/

const bool TEST = 0;

int test(ifstream& file) {
    while (file) {
        int n, answer;
        file >> n >> answer; 
        file.ignore(2);
        int solution = solve(n);
        if (answer != solution) {
            cout << "Failed test!\n";
            cout << "Ans: " << answer << ", Sol: " << solution;
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("Optimal sequence.txt");
        test(file);
    } else {
        int n;
        cin >> n;
        cout << solve(n);
    }
    return 0;
}