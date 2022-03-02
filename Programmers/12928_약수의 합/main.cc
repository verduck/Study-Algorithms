#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        if (!(n % i)) {
            answer += i;
        }
    }
    return answer;
}

int main() {
    int n = 12;
    int result = solution(n);
    cout << result << '\n';
    return 0;
}