#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int money, vector<int> costs) {
    int answer = 0;
    const vector<int> unit = { 1, 5, 10, 50, 100, 500 };
    vector<pair<double, int>> v;

    for (int i = 0; i < costs.size(); i++) {
        v.push_back({ static_cast<double>(costs[i]) / unit[i], i });
    }

    sort(v.begin(), v.end());

    for (const pair<double, int>& p : v) {
        int count = money / unit[p.second];
        answer += costs[p.second] * count;
        money -= unit[p.second] * count;
    }

    return answer;
}

int main() {
    int money = 4578;
    vector<int> costs = { 1, 4, 99, 35, 50, 1000 };
    int result = solution(money, costs);
    cout << result << '\n';
    return 0;
}