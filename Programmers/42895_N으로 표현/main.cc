#include <iostream>
#include <vector>
#include <unordered_set>

#define SIZE 8

using namespace std;

int combine_N(int N, int len) {
    int result = N;
    for (int i = 0; i < len; i++) {
        N *= 10;
        result += N;
    }

    return result;
}

int solution(int N, int number) {
    int answer = -1;
    vector<unordered_set<int>> memo(SIZE);

    if (N == number) {
        return 1;
    }

    memo[0].insert(N);

    for (int i = 1; i < SIZE; i++) {
        memo[i].insert(combine_N(N, i));

        for (int j = 0; j < i; j++) {
            for (int x : memo[j]) {
                for (int y : memo[i - j - 1]) {
                    memo[i].insert(x + y);
                    memo[i].insert(x - y);
                    memo[i].insert(x * y);
                    if (y) {
                        memo[i].insert(x / y);
                    }
                }
            }
        }

        if (memo[i].find(number) != memo[i].end()) {
            return i + 1;
        }
    }

    return answer;
}

int main() { 
    int N = 5;
    int number = 12;
    int result = solution(N, number);
    cout << result << '\n';
    return 0;
}