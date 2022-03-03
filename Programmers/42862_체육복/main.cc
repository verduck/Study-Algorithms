#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (auto lit = lost.begin(); lit != lost.end();) {
        auto rit = find(reserve.begin(), reserve.end(), *lit);
        if (rit != reserve.end()) {
            reserve.erase(rit);
            lit = lost.erase(lit);
        } else {
            lit++;
        }
    }

    for (auto lit = lost.begin(); lit != lost.end();) {
        auto rit = find(reserve.begin(), reserve.end(), *lit - 1);
        if (rit != reserve.end()) {
            reserve.erase(rit);
            lit = lost.erase(lit);
            continue;
        }

        rit = find(reserve.begin(), reserve.end(), *lit + 1);
        if (rit != reserve.end()) {
            reserve.erase(rit);
            lit = lost.erase(lit);
        } else {
            lit++;
        }
    }

    answer = n - lost.size();

    return answer;
}

int main() { 
    int n = 5;
    vector<int> lost = { 2, 4 };
    vector<int> reserve = { 3 };
    int answer = solution(n, lost, reserve);
    cout << answer << '\n';
    return 0;
}