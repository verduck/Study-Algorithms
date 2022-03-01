#include <iostream>

using namespace std;

int solution(int num) {
    int answer = 0;
    long n = num;
    while (n != 1) {
        if (n % 2) {
            n = n * 3 + 1;
        } else {
            n /= 2;
        }
        if (++answer >= 500) {
            answer = -1;
            break;
        }
    }

    return answer;
}

int main() {
    int n = 6;
    int result = solution(n);

    cout << result << '\n';
    return 0;
}