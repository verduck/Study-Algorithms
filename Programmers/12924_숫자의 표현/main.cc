#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int finn = 0;
        for (int j = i; j <= n; j++) {
            finn += j;
            if (finn >= n) {
                if (finn == n) {
                    answer++;
                }
                break;
            }
        }
    }
    return answer;
}

int main() {
    int n = 15;
    int result = solution(n);
    cout << result << '\n';
    return 0;
}