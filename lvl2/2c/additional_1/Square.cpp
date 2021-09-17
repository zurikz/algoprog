#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int solve(vector<vector<bool>> field) {
    size_t size = field.size();
    vector<vector<int>> a(size + 1, vector<int> (size + 1, 0));
    int maxSize = 0;
    for (size_t i = 1; i < a.size(); i++) {
        for (size_t j = 1; j < a.size(); j++) {
            if (field[i - 1][j - 1]) {
                a[i][j] = 1 + min(min(a[i][j - 1], a[i - 1][j]), a[i - 1][j - 1]);
            }
            maxSize = max(maxSize, a[i][j]);
        }
    }
    return maxSize;
}

/****** testing ******/

const bool TEST = 0;

vector<vector<bool>> readInput(istream& in) {
    int n;
    in >> n;
    vector<vector<bool>> field(n, vector<bool> (n, false));  
    for (int i = 0; i < n; i++) {
        string line;
        in >> line;
        for (int j = 0; j < n; j++) {
            if (line[j] == '#') {
                field[i][j] = true;
            }
        }
    }
    return field;
}

int test(ifstream& file) {
    int testNum = 1;
    while (file) {
        vector<vector<bool>> field = readInput(file);
        int answer;
        file >> answer;
        file.ignore(2);
        int solution = solve(field);
        if (answer != solution) {
            cout << "Failed test no. " << testNum << "!\n";
            cout << "Ans: " << answer << ", Sol: " << solution;
            return 1;
        }
        ++testNum;
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("Square.txt");
        test(file);
    } else {
        vector<vector<bool>> field = readInput(cin);
        cout << solve(field);
    }
    return 0;
}