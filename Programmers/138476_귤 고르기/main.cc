#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> m;

    for (int i : tangerine) {
        m[i]++;
    }

    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](const pair<int, int>& left, const pair<int, int>& right) {
        return left.second > right.second;
    });

    int n = 0;
    for (const pair<int, int>& p : v) {
        n += p.second;
        answer++;
        if (n >= k) {
            break;
        }
    }

    return answer;
}

int main() {
    int k = 6;
    vector<int> tangerine = { 1, 3, 2, 5, 4, 5, 2, 3 };

    int result = solution(k, tangerine);
    cout << result << '\n';
    return 0;
}