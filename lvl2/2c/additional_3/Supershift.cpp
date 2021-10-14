#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

void shift(vector<int>& vec, int k) {
    int size = vec.size();
    int cycles = gcd(size, abs(k));
    for (int i = 0; i < cycles; i++) {
        int currIdx = i;
        int curr = vec[i];
        for (int j = 0; j < size / cycles; j++) {
            int nextIdx = (currIdx + size + (k % size)) % size;
            int next = vec[nextIdx];
            vec[nextIdx] = curr;
            currIdx = nextIdx;
            curr = next;
        }
    }
}

/****** tesing ******/

const bool TEST = 0;

istream& operator>>(istream& in, vector<int>& vec) {
    for (auto& x : vec) {
        in >> x;
    }
    return in;
}

ostream& operator<<(ostream& out, const vector<int>& vec) {
    for (const auto& x : vec) {
        out << x << " ";
    }
    out << endl;
    return out;
}

tuple<int, vector<int>> readInput(istream& in) {
    int n, k;
    in >> n;
    vector<int> vec(n);
    in >> vec;
    in >> k;
    return tie(k, vec);
}

int test(ifstream& file) {
    int testNum = 1;
    while (file) {
        auto [k, vec] = readInput(file);
        vector<int> answer(vec.size());
        file >> answer;
        file.ignore(2);
        shift(vec, k);
        if (vec != answer) {
            cout << "Failed test no. " << testNum << endl;
            cout << "k = " << k << endl;
            cout << "Ans: " << answer;
            cout << "Sol: " << vec;
            return 1;
        }
        ++testNum;
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("Supershift.txt");
        test(file);
    } else {
        auto [k, vec] = readInput(cin);
        shift(vec, k);
        cout << vec;
    }
    return 0;
}