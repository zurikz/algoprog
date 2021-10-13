#include <algorithm>
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

tuple<double, int> Max(const vector<double>& vec) {
    auto maxIt = max_element(vec.begin(), vec.end());
    auto argmax = static_cast<int>(distance(vec.begin(), maxIt));
    return make_tuple(*maxIt, argmax);
}

tuple<double, vector<int>> solve(const vector<int>& input) {
    vector<vector<double>> ans(input.size() + 1);
    vector<vector<int>> from(input.size() + 1);
    for (int i = 1; i <= (int)ans.size() - 1; i++) {
        ans[i] = vector<double> (input[i - 1], 0);
        from[i] = vector<int> (input[i - 1], 0);
        for (int curr = 1; curr <= (int)ans[i].size(); curr++) {
            double max = 0;
            int fromPrev = input[i - 1];
            for (int prev = 1; prev <= (int)ans[i - 1].size(); prev++) {
                double rating = ans[i - 1][prev - 1] + (double) curr / prev;
                if (rating > max) {
                    max = rating;
                    fromPrev = prev;
                }
            }
            ans[i][curr - 1] = max;
            from[i][curr - 1] = fromPrev;
        }
    }
    auto [max, argmax] = Max(ans.back());
    vector<int> seq = {1 + argmax};
    for (int i = (int)ans.size() - 1; i >= 2; i--) {
        seq.push_back(from[i][seq.back() - 1]);
    }
    reverse(seq.begin(), seq.end());
    return tie(max, seq);
}

/****** tesing ******/

const bool TEST = 0;

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