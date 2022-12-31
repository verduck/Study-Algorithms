#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int divisor(int n) {
    if (n == 1) {
        return 0;
    }
    for (int j = 2; j <= sqrt(n); j++) {
        if (n % j == 0 && n / j <= 10000000) {
            return n / j;
        }
    }
    return 1;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;

    for (int i = begin; i <= end; i++) {
        answer.push_back(divisor(i));
    }

    return answer;
}

int main() {
    long long begin = 1;
    long long end = 10;
    vector<int> result = solution(begin, end);
    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}