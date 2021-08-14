#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solveTowerOfHanoi(
    vector<stack<unsigned>>& rods, int n, int source, int target, int medium
) {
    if (n > 0) {
        solveTowerOfHanoi(rods, n - 1, source, medium, target);
        rods[target].push(rods[source].top());
        rods[source].pop();
        cout << n << " " << source + 1 << " " << target + 1 << endl;
        solveTowerOfHanoi(rods, n - 1, medium, target, source);
    }
}

int main() {
    int n;
    cin >> n;
    vector<stack<unsigned>> rods(3);
    for (unsigned i = n; i > 0; --i) {
        rods[0].push(i);
    }
    solveTowerOfHanoi(rods, n, 0, 2, 1);
    return 0;
}