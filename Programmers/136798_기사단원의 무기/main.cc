#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int number_of_divisors(int n) {
    int result = 0;
    
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) {
                result++;
            } else {
                result += 2;
            }
        }
    }

    return result;
}

int solution(int number, int limit, int power) {
    int answer = 0;

    for (int i = 1; i <= number; i++) {
        int n = number_of_divisors(i);
        if (n > limit) {
            answer += power;
        } else {
            answer += n;
        }
    }

    return answer;
}

int main() {
    int number = 10;
    int limit = 3;
    int power = 2;

    int result = solution(number, limit, power);
    cout << result << '\n';
    return 0;
}