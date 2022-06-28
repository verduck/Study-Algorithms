#include <iostream>
#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

long long f(vector<int>& memo, int n);

int solution(int n) {
    int answer = 0;
    vector<int> memo(5001, 0);
    memo[2] = 3;
    memo[4] = 11;
    answer = f(memo, n);
    return answer;
}

long long f(vector<int>& memo, int n) {
    if (n % 2 == 1) {
        return 0;
    } else if (memo[n] != 0) {
        return memo[n];
    } else {
        return memo[n] = ((f(memo, n - 2) * 4 % MOD) - (f(memo, n - 4) % MOD) + MOD) % MOD;
    }
}

int main() {
    int n = 8;
    int answer = solution(n);
    cout << answer << '\n';
    return 0;
}