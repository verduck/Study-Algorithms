#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while (n / a != 0) {
        int quotient = n / a;
        int remainder = n - quotient * a;
        answer += quotient * b;
        n = quotient * b + remainder;
    }

    return answer;
}

int main() {
    int a = 3;
    int b = 2;
    int n = 10;
    int result = solution(a, b, n);
    cout << result << '\n';
    return 0;
}