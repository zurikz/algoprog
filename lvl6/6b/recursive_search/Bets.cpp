#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

struct Bet {
    int winner, looser;
};

typedef pair<Bet, Bet> User;

bool checkBet(const vector<int>& a, const Bet& bet) {
    size_t winnerPos, looserPos;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] == bet.winner) {
            winnerPos = i;
        }
        if (a[i] == bet.looser) {
            looserPos = i;
        }
    }
    if (winnerPos < looserPos) {
        return true;
    }
    return false;
}

void check(const vector<int>& a, const vector<User>& users, string& answer) {
    for (const auto& user : users) {
        bool firstBet = checkBet(a, user.first);
        bool secondBet = checkBet(a, user.second);
        if (firstBet == secondBet) {
            return;
        }
    }
    answer = "";
    for (size_t i = 0; i < a.size() - 1; i++) {
        answer += to_string(a[i]) + " ";
    }
    answer += to_string(a.back());
}

void permute(
    vector<int>& a, vector<bool>& was, int i, 
    const vector<User>& users, string& answer
) {
    if (answer != "0") {
        return;
    }
    if (i == static_cast<int>(a.size())) {
        check(a, users, answer);
        return;
    }
    for (int j = 1; j <= static_cast<int>(a.size()); j++) {
        if (!was[j]) {
            a[i] = j;
            was[j] = true;
            permute(a, was, i + 1, users, answer);
            was[j] = false;
        }
    }
}

string solve(int k, vector<User> users) {
    vector<int> a(k);
    vector<bool> was(k);
    string answer = "0";
    permute(a, was, 0, users, answer);
    return answer;
}

/****** testing ******/

const bool TEST = 0;

tuple<int, vector<User>> readInput(istream& in) {
    int k, n;
    in >> k >> n;
    vector<User> users(n);
    for (auto& user : users) {
        in >> user.first.winner;
        in >> user.first.looser;
        in >> user.second.winner;
        in >> user.second.looser;
    }
    return tie(k, users);
}

int test(ifstream& file) {
    int count = 1;
    while (file) {
        auto [k, users] = readInput(file);
        file.ignore(1);
        string answer;
        getline(file, answer);
        file.ignore(1);
        string solution = solve(k, users);
        if (solution != answer) {
            cout << "Failed test!\n";
            cout << "Test no. " << count << endl;
            cout << "Answer: " << answer << endl;
            cout << "Solution: " << solution;
            return 1;
        }
        ++count;
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("Bets.txt");
        test(file);
    } else {
        auto [k, users] = readInput(cin);
        cout << solve(k, users);
    }
    return 0;
}