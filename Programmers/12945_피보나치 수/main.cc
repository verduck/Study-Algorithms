#include <iostream>
#include <string>
#include <vector>

using namespace std;

int fibonacci(vector<int>& memo, int n) {
    if (memo[n] != -1) {
        return memo[n];
    }

    return memo[n] = (fibonacci(memo, n - 1) + fibonacci(memo, n - 2)) % 1234567;
}

int solution(int n) {
    int answer = 0;
    vector<int> memo(100001, -1);
    memo[0] = 0;
    memo[1] = 1;
    answer = fibonacci(memo, n);
    return answer;
}

int main() {
    int n = 3;
    int result = solution(n);
    cout << result << '\n';
    return 0;
}