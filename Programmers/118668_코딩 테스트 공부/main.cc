#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    vector<vector<int>> dp;
    int target_alp = 0;
    int target_cop = 0;
    for (const vector<int>& v : problems) {
        target_alp = max(target_alp, v[0]);
        target_cop = max(target_cop, v[1]);
    }
    alp = min(target_alp, alp);
    cop = min(target_cop, cop);
    
    dp.assign(target_alp + 1, vector<int>(target_cop + 1, INT_MAX));
    dp[alp][cop] = 0;

    for (int i = alp; i <= target_alp; i++) {
        for (int j = cop; j <= target_cop; j++) {
            int alp_rwd = min(i + 1, target_alp);
            int cop_rwd = min(j + 1, target_cop);
            dp[alp_rwd][j] = min(dp[i][j] + 1, dp[alp_rwd][j]);
            dp[i][cop_rwd] = min(dp[i][j] + 1, dp[i][cop_rwd]);

            for (const vector<int>& v : problems) {
                if (i >= v[0] && j >= v[1]) {
                    alp_rwd = min(i + v[2], target_alp);
                    cop_rwd = min(j + v[3], target_cop);
                    dp[alp_rwd][cop_rwd] = min(dp[i][j] + v[4], dp[alp_rwd][cop_rwd]);
                }
            }
        }
    }

    answer = dp[target_alp][target_cop];
    return answer;
}

int main() {
    int alp = 0;
    int cop = 0;
    vector<vector<int>> problems = { { 0, 0, 2, 1, 2 }, { 4, 5, 3, 1, 2 }, { 4, 11, 4, 0, 2 }, { 10, 4, 0, 4, 2 } };
    int result = solution(alp, cop, problems);
    cout << result << '\n';
    return 0;
}