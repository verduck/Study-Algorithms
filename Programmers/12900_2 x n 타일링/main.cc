#include <iostream>
#include <string>
#include <vector>

using namespace std;

int fn(vector<int>& memo, int n) {
    if (n == 0) {
        return 0;
    }
    if (memo[n - 1]) {
        return memo[n - 1];
    }

    return memo[n - 1] = (fn(memo, n - 1) + fn(memo, n - 2)) % 1000000007;
}

int solution(int n) {
    int answer = 0;
    vector<int> memo(n, 0);
    memo[0] = 1;
    memo[1] = 2;
    answer = fn(memo, n);
    return answer;
}

int main() {
    int n = 4;
    int result = solution(n);
    cout << result << '\n';
    return 0;
}