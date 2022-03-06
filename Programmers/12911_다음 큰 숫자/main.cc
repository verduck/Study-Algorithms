#include <iostream>
#include <bitset>

using namespace std;

int solution(int n) {
    int answer = n ;
    bitset<32> nb(n);

    while (true) {
        bitset<32> mb(++answer);
        if (nb.count() == mb.count()) {
            break;
        }
    }

    return answer;
}

int main() {
    int n = 78;
    long long answer = solution(n);
    cout << answer << '\n';
    return 0;
}