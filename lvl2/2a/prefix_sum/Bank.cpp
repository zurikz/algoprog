#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

using namespace std;

const bool TEST = 1;

vector<int> makeSuffMaxIndices(const vector<int>& vec) {
    // Indices of max elements instead of max values
    vector<int> suffMaxIndices(vec.size());
    suffMaxIndices[vec.size() - 1] = vec.size() - 1;
    for (int i = vec.size() - 2; i >= 0; --i) {
        if (vec[suffMaxIndices[i + 1]] <= vec[i]) {
            suffMaxIndices[i] = i;
        } else {
            suffMaxIndices[i] = suffMaxIndices[i + 1];
        }
    }
    return suffMaxIndices;
}

vector<int> solve(const vector<int>& vec, int k) {
    vector<int> suffMaxIndices = makeSuffMaxIndices(vec);
    return {suffMaxIndices[0] + 1, suffMaxIndices[k + 1] + 1};
}

/****** testing ******/

istream& operator>>(istream& in, vector<int>& vec) {
    for (auto& x : vec) {
        in >> x;
    }
    return in;
}

ostream& operator<<(ostream& out, const vector<int>& vec) {
    for (const auto& x : vec) {
        cout << x << " ";
    }
    cout << endl;
    return out;
}

tuple<vector<int>, int> readInput(istream& in) {
    int n, k;
    in >> n >> k;
    vector<int> vec(n);
    in >> vec;
    return tie(vec, k);
}

int test(ifstream& file) {
    while (file) {
        auto [vec, k] = readInput(file);
        vector<int> answer(2);
        file >> answer;
        file.ignore(2);
        vector<int> solution = solve(vec, k);
        if (answer != solution) {
            cout << "Failed test!" << endl;
            cout << k << endl;
            cout << vec;
            cout << answer;
            cout << solution;
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("Bank.txt");
        test(file);
    } else {
        auto [vec, k] = readInput(cin);
        vector<int> solution = solve(vec, k);
        cout << solution[0] << " " << solution[1];
    }
    return 0;
}