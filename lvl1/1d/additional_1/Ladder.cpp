#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

vector<int> makeLadder(const vector<int>& cards) {
    int num2freq[5001] = {0};
    int max = -1;
    for (size_t i = 0; i < cards.size(); i++) {
        ++num2freq[cards[i]];
        max = std::max(max, cards[i]);
    }

    vector<int> ladder;
    for (size_t i = 1; i <= max; i++) {
        if (num2freq[i]) {
            ladder.push_back(i);
            --num2freq[i];
        }
    }
    for (size_t i = max - 1; i > 0; i--) {
        if (num2freq[i]) {
            ladder.push_back(i);
        }
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