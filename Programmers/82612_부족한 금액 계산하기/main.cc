#include <iostream>

using namespace std;

long long solution(int price, int money, int count) {
    long long answer = 0;

    for (int i = 1; i <= count; i++) {
        answer += price * i;
    }

    answer -= money;

    if (answer < 0) {
        answer = 0;
    }

    return answer;
}

int main() {
    int price = 3;
    int money = 20;
    int count = 4;
    long long answer = solution(price, money, count);
    cout << answer << '\n';
    return 0;
}
