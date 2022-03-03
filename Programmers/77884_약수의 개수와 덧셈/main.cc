#include <iostream>

using namespace std;

bool is_even_nofs(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!(n % i)) {
            count++;
        }
    }

    return !(count % 2);
}

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; i++) {
        if (is_even_nofs(i)) {
            answer += i;
        } else {
            answer -= i;
        }
    }

    return answer;
}

int main() {
    int left = 13;
    int right = 17;
    int answer = solution(left, right);
    cout << answer << '\n';
    return 0;
}