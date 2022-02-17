#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int m = 0;
        for (int j = i; j <= n; j++) {
            m += j;
            if (m >= n) {
                if (m == n) {
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