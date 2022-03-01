#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;

    while (n) {
        answer += n % 10;
        n /= 10;
    }

    return answer;
}

int main() {
    int n = 987;
    int result = solution(n);
    cout << result << '\n';
    return 0;
}