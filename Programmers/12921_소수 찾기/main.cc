#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> prime_numbers(n + 1, true);

    for (int i = 2; i * i <= n; i++) {
        if (prime_numbers[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime_numbers[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (prime_numbers[i]) {
            answer++;
        }
    }

    return answer;
}

int main() {
    int n = 10;
    int result = solution(n);
    cout << result << '\n';
    return 0;
}