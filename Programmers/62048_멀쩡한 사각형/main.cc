#include <iostream>
#include <numeric>

using namespace std;

long long solution(int w,int h) {
    long long answer = static_cast<long long>(w) * h - (w + h - gcd(w, h));
    return answer;
}

int main() {
    int w = 8;
    int h = 12;
    long long result = solution(w, h);
    cout << result << '\n';
    return 0;
}