#include <iostream>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> memo(n, vector<int>(m, 1));

    for (const vector<int>& v : puddles) {
        memo[v[1] - 1][v[0] - 1] = 0;
    }

    bool puddle = false;
    for (int i = 0; i < m; i++) {
        if (puddle) {
            memo[0][i] = 0;
        }
        if (!memo[0][i]) {
            puddle = true;
        }
    }

    puddle = false;
    for (int i = 0; i < n; i++) {
        if (puddle) {
            memo[i][0] = 0;
        }
        if (!memo[i][0]) {
            puddle = true;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (memo[i][j]) {
                memo[i][j] = (memo[i - 1][j] + memo[i][j - 1]) % 1000000007;
            }
        }
    }

    answer = memo[n - 1][m - 1];
    return answer;
}

int main() { 
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles = { { 2, 2 } };
    int result = solution(m, n, puddles);
    cout << result << '\n';
    return 0;
}