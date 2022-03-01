#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    double d = sqrt(n);
    if (d - static_cast<int>(d)) {
        answer = -1;
    } else {
        answer = pow(d + 1, 2);
    }
    return answer;
}

int main() {
    long long n = 3;
    long long result = solution(n);

    cout << result << '\n';
    return 0;
}