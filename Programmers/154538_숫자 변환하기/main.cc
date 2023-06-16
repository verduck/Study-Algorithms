#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    vector<int> memo(y + 1, INT_MAX);

    memo[x] = 0;

    for (int i = x; i <= y; i++) {
        if (memo[i] == INT_MAX) {
            continue;
        }
        if (i + n <= y) {
            memo[i + n] = min(memo[i + n], memo[i] + 1);
        }
        if (i * 2 <= y) {
            memo[i * 2] = min(memo[i * 2], memo[i] + 1);
        }
        if (i * 3 <= y) {
            memo[i * 3] = min(memo[i * 3], memo[i] + 1);
        }
    }

    answer = memo[y] == INT_MAX ? -1 : memo[y];

    return answer;
}

int main() {
    int x = 10;
    int y = 40;
    int n = 5;

    int result = solution(x, y, n);

    cout << result << '\n';

    return 0;
}