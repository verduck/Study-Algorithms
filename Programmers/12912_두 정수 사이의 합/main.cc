#include <iostream>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;

    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    for (int i = a; i <= b; i++) {
        answer += i;
    }

    return answer;
}

int main() {
    int a = 3;
    int b = 5;
    long long result = solution(a, b);
    cout << result << '\n';
    return 0;
}