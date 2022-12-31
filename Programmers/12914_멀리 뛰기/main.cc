#include <iostream>
#include <string>
#include <vector>

#define MOD 1234567

using namespace std;

long long long_jump(int n, vector<long long>& memo) {
    if (memo[n] != 0) {
        return memo[n];
    }

    return memo[n] = (long_jump(n - 1, memo) + long_jump(n - 2, memo)) % MOD;
}

long long solution(int n) {
    long long answer = 0;
    vector<long long> memo(n + 1, 0);
    memo[1] = 1;
    memo[2] = 2;
    answer = long_jump(n, memo);
    return answer;
}

int main() {
    int n = 4;
    long long result = solution(n);
    cout << result << '\n';
    return 0;
}