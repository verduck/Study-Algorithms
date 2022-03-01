#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> v;

    while (n) {
        v.push_back(n % 10);
        n /= 10;
    }

    sort(v.begin(), v.end());

    while (!v.empty()) {
        answer *= 10;
        answer += v.back();
        v.pop_back();
    }

    return answer;
}

int main() {
    long long n = 118372;
    long long result = solution(n);
    cout << result << '\n';
    return 0;
}