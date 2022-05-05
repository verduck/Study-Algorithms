#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/*
int bino_coef(vector<vector<int>>& memo, int n, int r) {
    if (r > n) {
        return 0;
    }

    if (memo[n][r] > 0) {
        return memo[n][r];
    }

    if (r == 0 || r == n) {
        return memo[n][r] = 1;
    }

    return memo[n][r] = (bino_coef(memo, n - 1, r) + bino_coef(memo, n - 1, r - 1)) % 10000019;
}

int solution(int width, int height, vector<vector<int>> diagonals) {
    int answer = 0;

    int n = width + height;
    int r = width;

    vector<vector<int>> memo(n + 1, vector<int>(r + 1, 0));

    answer = bino_coef(memo, n, r);

    return answer;
}
*/

int solution(int width, int height, vector<vector<int>> dianonals) {
    int answer = 0;
    vector<vector<int>> memo(height + 1, vector<int>(width + 1, 0));

    for (int i = 0; i < memo.size(); i++) {
        for (int j = 0; j < memo[i].size(); j++) {
            if (i == 0 || j == 0) {
                memo[i][j] = 1;
            } else {
                memo[i][j] = (memo[i - 1][j] + memo[i][j - 1]) % 10000019;
            }
        }
    }

    for (const vector<int>& v : memo) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    answer = memo[height][width];

    return answer;
}

int main() {
    int width = 2;
    int height = 2;
    vector<vector<int>> diaonals = { { 1, 1 }, { 2, 2 } };
    int result = solution(width, height, diaonals);
    cout << result << '\n';
    return 0;
}