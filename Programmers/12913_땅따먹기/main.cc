#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land) {
    int answer = 0;
    vector<vector<int>> memo(land.size() + 1, vector<int>(4, 0));

    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < 4; j++) {
            memo[i + 1][j] = land[i][j];
        }
    }

    for (int i = 1; i < memo.size(); i++) {
        memo[i][0] = max(memo[i][0] + memo[i - 1][1], max(memo[i][0] + memo[i - 1][2], memo[i][0] + memo[i - 1][3]));
        memo[i][1] = max(memo[i][1] + memo[i - 1][0], max(memo[i][1] + memo[i - 1][2], memo[i][1] + memo[i - 1][3]));
        memo[i][2] = max(memo[i][2] + memo[i - 1][0], max(memo[i][2] + memo[i - 1][1], memo[i][2] + memo[i - 1][3]));
        memo[i][3] = max(memo[i][3] + memo[i - 1][0], max(memo[i][3] + memo[i - 1][1], memo[i][3] + memo[i - 1][2]));
    }

    answer = *max_element(memo[land.size()].begin(), memo[land.size()].end());

    return answer;
}

int main() {
    vector<vector<int>> land = { { 1, 2, 3, 5 }, { 5, 6, 7, 8 }, { 4, 3, 2, 1 } };
    int result = solution(land);
    cout << result << '\n';
    return 0;
}