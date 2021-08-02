#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

const bool TEST = 0;

struct Query {
    unsigned int x1, y1;
    unsigned int x2, y2;
};

vector<vector<int>> make2dPrefixSums(const vector<vector<int>>& matrix) {
    size_t rows = matrix.size() + 1;
    size_t cols = matrix[0].size() + 1;
    vector<vector<int>> pref(rows, vector<int> (cols, 0));

    for (size_t row = 1; row < rows; row++) {
        for (size_t col = 1; col < cols; col++) {
            pref[row][col] = matrix[row - 1][col - 1] + pref[row - 1][col] 
                            + pref[row][col - 1] - pref[row - 1][col - 1];
        }
    }
    return pref;
}

vector<int> planeSum(const vector<vector<int>>& matrix, const vector<Query>& queries) {
    vector<int> sums;
    vector<vector<int>> pref = make2dPrefixSums(matrix);
    for (const Query& q : queries) {
        int sum = pref[q.x2][q.y2] - pref[q.x1 - 1][q.y2] - pref[q.x2][q.y1 - 1]
                + pref[q.x1 - 1][q.y1 - 1]; 
        sums.push_back(sum);
    }
    return sums;
}

/****** testing ******/

template <typename T>
istream& operator>>(istream& in, vector<T>& vec) {
    for (auto& x : vec) {
        in >> x;
    }
    return in;
}

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vec) {
    out << " ";
    for (const auto& x : vec) {
        out << x << " ";
    }
    out << endl;
    return out;
}

tuple<vector<vector<int>>, vector<Query>> readInput(istream& file) {
    int n, m, k;
    file >> n >> m >> k;
    vector<vector<int>> matrix(n, vector<int> (m, 0));
    file >> matrix;

    vector<Query> queries(k);
    for (Query& q : queries) {
        file >> q.x1 >> q.y1 >> q.x2 >> q.y2;
    }
    return tie(matrix, queries);
}

vector<int> readAnswer(ifstream& file, int k) {
    vector<int> answers(k);
    file >> answers;
    string line;
    getline(file, line);
    return answers;
}

int test(ifstream& file) {
    while (file) {
        auto [matrix, queries] = readInput(file);
        vector<int> answers = readAnswer(file, queries.size());
        vector<int> solutions = planeSum(matrix, queries);
        if (solutions != answers) {
            cout << "Failed test!" << endl;
            cout << matrix;
            for (const auto& q : queries) {
                cout << "(" << q.x1 << ", " << q.y1 << ") ";
                cout << "(" << q.x2 << ", " << q.y2 << ") " << endl;
            }
            cout << answers;
            cout << solutions;
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("2d sum.txt");
        test(file);
    } else {
        auto [matrix, queries] = readInput(std::cin);
        vector<int> solutions = planeSum(matrix, queries);
        for (const auto& s : solutions) {
            cout << s << endl;
        }
    }
    return 0;
}