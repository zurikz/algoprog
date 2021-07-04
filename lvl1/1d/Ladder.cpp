#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

void merge(vector<int>& v, size_t leftStart, size_t leftEnd, size_t rightEnd) {
    int leftSize = leftEnd - leftStart + 1;
    int rightSize = rightEnd - leftEnd;
    int leftArray[leftSize + 1], rightArray[rightSize + 1];
    for (size_t i = leftStart; i <= leftEnd; ++i) {
        leftArray[i - leftStart] = v[i];
    }
    for (size_t i = leftEnd + 1; i <= rightEnd; ++i) {
        rightArray[i - (leftEnd + 1)] = v[i];
    }
    size_t leftIdx = 0;
    size_t rightIdx = 0;
    leftArray[leftSize] = numeric_limits<int>::min();
    rightArray[rightSize] = numeric_limits<int>::min();
    for (size_t i = leftStart; i <= rightEnd; ++i) {
        if (leftArray[leftIdx] > rightArray[rightIdx]) {
            v[i] = leftArray[leftIdx];
            ++leftIdx;
        } else {
            v[i] = rightArray[rightIdx];
            ++rightIdx;
        }
    }
}

void mergeSortDesc(vector<int>& v, size_t startIdx, size_t endIdx) {
    if (startIdx < endIdx) {
        size_t q = (startIdx + endIdx) / 2;
        mergeSortDesc(v, startIdx, q);
        mergeSortDesc(v, q + 1, endIdx);
        merge(v, startIdx, q, endIdx);
    }
}

vector<int> makeLadder(vector<int> cards) {
    vector<int> left, right, ladder;
    mergeSortDesc(cards, 0, cards.size() - 1);
    int max = cards[0];
    right.push_back(max);
    for (size_t i = 1; i < cards.size(); ++i) {
        if (cards[i] == max) {
            continue;
        } else if (cards[i] < cards[i - 1]) {
            right.push_back(cards[i]);
        } else if (left.empty()) {
            left.push_back(cards[i]);
        } else if (cards[i] != left[left.size() - 1]) {
            left.push_back(cards[i]);
        }
    }
    if (left.size() > 0) {
        for (int i = left.size() - 1; i >= 0; --i) {
            ladder.push_back(left[i]);
        }
    }
    for (size_t i = 0; i < right.size(); ++i) {
        ladder.push_back(right[i]);
    }
    return ladder;
}

/************** testing **************/

istream& operator>>(istream& istream1, vector<int>& v) {
    for (int& x : v) {
        istream1 >> x;
    }
    return istream1;
}

ostream& operator<<(ostream& ostream1, const vector<int>& v) {
    for (const int& x : v) {
        ostream1 << x << " ";
    }
    return ostream1;
}

tuple<vector<int>, vector<int>> readTest(ifstream& file) {
    string line;
    getline(file, line);

    int m;
    file >> m;
    vector<int> cards(m);
    file >> cards;
    file.ignore();

    getline(file, line);

    file >> m;
    vector<int> ladder(m);
    file >> ladder;
    file.ignore();

    getline(file, line);
    return make_tuple(cards, ladder);
}

int test(ifstream& file) {
    while (file) {
        vector<int> cards, answer;
        tie(cards, answer) = readTest(file);
        vector<int> solution = makeLadder(cards);
        if (solution != answer) {
            cout << "Failed test!" << endl;
            cout << "Input: " << cards << endl;
            cout << "Answer: " << answer << endl;
            cout << "My answer: " << solution << endl;
            return 1;
        }
    }
    cout << "OK!";
    return 0;
}

int main() {
    // ifstream file("Ladder.txt");
    // test(file);

    int m;
    cin >> m;
    vector<int> cards(m);
    cin >> cards;

    vector<int> ladder = makeLadder(cards);
    cout << ladder.size() << endl;
    cout << ladder << endl;
    return 0;
}