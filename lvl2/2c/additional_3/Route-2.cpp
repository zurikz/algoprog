#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

using namespace std;

typedef vector<vector<int>> Table;

int solve(const Table& table, int k) {
    int n = table.size() - 2;
    Table ansPrev(n + 2, vector<int> (n + 2, 0));
    Table ans(n + 2, vector<int> (n + 2, 0));
    for (int pass = 1; pass <= k; pass++) {
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                ans[i][j] = table[i][j] + max(
                    ansPrev[i - 1][j], 
                    max(ansPrev[i][j - 1], max(ansPrev[i + 1][j], ansPrev[i][j + 1]))
                );
            }
        }
        ansPrev = ans;
    }
    return ans[1][1];
}

/****** testing ******/

const bool TEST = 0;

tuple<Table, int> readInput(istream& in) {
    int n, k;
    in >> n >> k;
    Table table(n + 2, vector<int> (n + 2, 0));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            in >> table[i][j];
        }
    }
    return tie(table, k);
}

int test(ifstream& file) {
    int testNum = 1;
    while (file) {
        auto [table, k] = readInput(file);
        file.ignore();
        int answer;
        file >> answer;
        file.ignore(2);
        int solution = solve(table, k);
        if (solution != answer) {
            cout << "Failed test!\n";
            cout << "Test No. " << testNum << endl;
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
        ifstream file("Route-2.txt");
        test(file);
    } else {
        auto [table, k] = readInput(cin);
        cout << solve(table, k);
    }
    return 0;
}