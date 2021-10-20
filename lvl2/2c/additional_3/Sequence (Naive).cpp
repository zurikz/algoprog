#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

void increment(vector<int>& vec) {
    for (int& x : vec) {
        x = (x + 1) % 3;
    }
}

int solve(unsigned long long k) {
    int count = 0;
    while (k != 1) {
        k -= pow(2, ceil(log2(k) - 1));
        ++count;
    }
    return count % 3;
}

int naive(unsigned long long k) {
    vector<int> prev;
    vector<int> seq = {0};
    for (unsigned long long i = 1; i < k; i *= 2){
        prev = seq;
        increment(prev);
        seq.resize(2 * seq.size());
        for (int j = prev.size(); j < seq.size(); j++) {
            seq[j] = prev[j - prev.size()];
        }
    }
    return seq[k - 1];
}

void generateTests(ofstream& file) {
    for (int k = 1; k <= 50; k++) {
        file << k << endl;
        file << naive(k) << endl;
        file << endl;
    }
    for (int k = 100; k <= 1000; k += 100) {
        file << k << endl;
        file << naive(k) << endl;
        file << endl;
    }
    cout << "Tests are ready!\n";
}

int test(unsigned long long lowBound, unsigned long long highBound) {
    for (unsigned long long k = lowBound; k <= highBound; k++) {
        cout << k << " ";
        int naiveAns = naive(k);
        int solution = solve(k);
        if (naiveAns != solution) {
            cout << "k = " << k << endl; 
            cout << "naive = " << naiveAns << endl;
            cout << "sol = " << solution << endl;
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    // ofstream file("Sequence.txt");
    // generateTests(file);
    test(4, 512);
    return 0;
}