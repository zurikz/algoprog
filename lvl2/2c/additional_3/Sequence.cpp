// https://algoprog.ru/material/p111589
#include <iostream>
#include <fstream>

using namespace std;

int solve(unsigned long long k) {
    int count = 0;
    unsigned long long power = 1;
    while (k != 1) {
        while (power < k) {
            power *= 2;
        }
        k -= power / 2;
        power = 1;
        ++count;
    }
    return count % 3;
}

/****** testing ******/

const bool TEST = 0;

int test(ifstream& file) {
    int testNum = 1;
    while (file) {
        unsigned long long k;
        file >> k;
        int answer;
        file >> answer;
        file.ignore(2);
        int solution = solve(k);
        if (solution != answer) {
            cout << "Failed test no. " << testNum << endl;
            cout << "k = " << k << endl;
            cout << "asnwer = " << answer;
            cout << ", solution = " << solution << endl;
            return 1;
        }
        ++testNum;
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("Sequence.txt");
        test(file);
    } else {
        unsigned long long k;
        cin >> k;
        cout << solve(k);
    }
    return 0;
}