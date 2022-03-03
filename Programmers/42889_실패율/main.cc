#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    unordered_map<int, double> failure_rates;
    int m = stages.size();

    for (int i = 1; i <= N; i++) {
        if (m <= 0) {
            failure_rates.insert({ i, 0 });
        }
        int s = 0;
        for (int j : stages) {
            if (j == i) {
                s++;
            }
        }
        failure_rates.insert({ i, static_cast<double>(s) / m });
        m -= s;
    }

    vector<pair<int, double>> mv(failure_rates.begin(), failure_rates.end());
    sort(mv.begin(), mv.end(), [](const pair<int, double>& left, const pair<int, double>& right) {
        if (left.second == right.second) {
            return left.first < right.first;
        }
        return left.second > right.second;
    });

    for (const pair<int, double>& p : mv) {
        answer.push_back(p.first);
    }
    return answer;
}

int main() { 
    int N = 5;
    vector<int> stages = { 2,1,2,4,2,4,3,3 };
    vector<int> answer = solution(N, stages);
    for (int i : answer) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}