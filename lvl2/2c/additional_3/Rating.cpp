#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <tuple>

using namespace std;

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vec) {
    for (const auto& x : vec) {
        cout << x << " ";
    }
    cout << endl;
    return out;
}

tuple<double, vector<int>> solve(const vector<int>& input) {
    vector<vector<int>> seqPrev = {{input[0]}};
    if (input.size() == 1) {
        return make_tuple(0, seqPrev.back());
    }
    vector<double> ansPrev(input[0]);
    for (int day = 1; day < (int)input.size(); day++) {
        vector<double> ans(input[day]);
        vector<vector<int>> seq(input[day]);
        for (int curr = 1; curr <= (int)ans.size(); curr++) {
            double max = 0;
            vector<int> maxSeq;
            for (int prev = 1; prev <= (int)ansPrev.size(); prev++) {
                double rating = ansPrev[prev - 1] + (double) curr / prev;
                vector<int> vec = seqPrev[prev - 1];
                vec.push_back(curr);
                if (rating > max) {
                    max = rating;
                    maxSeq = vec;
                }
            }
            ans[curr - 1] = max;
            seq[curr - 1] = maxSeq;
        }
        ansPrev = ans;
        seqPrev = seq;
    }
    return tie(ansPrev.back(), seqPrev.back());
}

/****** tesing ******/

const bool TEST = 1;

vector<int> readInput(istream& in) {
    int n;
    in >> n;
    vector<int> days(n);
    for (auto& tasks : days) {
        in >> tasks;
    }
    return days;
}

int test(ifstream& file) {
    int count = 1;
    while (file) {
        vector<int> input = readInput(file);
        file.ignore();
        double answerRating;
        file >> answerRating;
        vector<int> answerVec(input.size());
        for (auto& x : answerVec) {
            file >> x;
        }
        file.ignore(2);
        auto [solRating, solVec] = solve(input);
        if (tie(solRating, solVec) != tie(answerRating, answerVec)) {
            cout << "Failed test no. " << count << endl;
            cout << "Ans:\n";
            cout << answerRating << endl;
            cout << answerVec;
            cout << "Sol:\n";
            cout << solRating << endl;
            cout << solVec;
            return 1;
        }
        ++count;
    }
    cout << "OK!";
    return 0;
}

int main() {
    if (TEST) {
        ifstream file("Rating.txt");
        test(file);
    } else {
        vector<int> input = readInput(cin);
        auto [maxRating, optimalTasks] = solve(input);
        cout << setprecision(5) << fixed;
        cout << maxRating << endl;
        cout << optimalTasks;
    }
    return 0;
}