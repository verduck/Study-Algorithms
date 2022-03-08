#include <iostream>
#include <vector>

using namespace std;

long long f(long long n) {
    long long result;

    if (!(n % 2)) {
        result = n + 1;
    } else {
        long long b = 1;
        while (n & b) {
            b <<= 1;
        }
        b >>= 1;
        result = n + b;
    }

    return result;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (long long l : numbers) {
        answer.push_back(f(l));
    }

    return answer;
}

int main() {
    vector<long long> numbers = { 2, 7 };
    vector<long long> answer = solution(numbers);
    for (long long l : answer) {
        cout << l << ' ';
    }
    cout << '\n';
    return 0;
}