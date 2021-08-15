#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solveTowerOfHanoi(
    int n, int source, int target, int medium
) {
    if (n > 0) {
        solveTowerOfHanoi(n - 1, source, medium, target);
        cout << n << " " << source + 1 << " " << target + 1 << endl;
        solveTowerOfHanoi(n - 1, medium, target, source);
    }
}

int main() {
    int n;
    cin >> n;
    solveTowerOfHanoi(n, 0, 2, 1);
    return 0;
}