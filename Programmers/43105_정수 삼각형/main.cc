#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> memo = triangle;
    int len = memo.size();

    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            memo[i + 1][j] = max(memo[i + 1][j], memo[i][j] + triangle[i + 1][j]);
            memo[i + 1][j + 1] = max(memo[i + 1][j + 1], memo[i][j] + triangle[i + 1][j + 1]);
        }
    }

    answer = *max_element(memo[len - 1].begin(), memo[len - 1].end());
    return answer;
}

int main() { 
    vector<vector<int>> triangle = { { 7 }, { 3, 8 }, { 8, 1, 0 }, { 2, 7, 4, 4 }, { 4, 5, 2, 6, 5 } };
    int result = solution(triangle);
    cout << result << '\n';
    return 0;
}