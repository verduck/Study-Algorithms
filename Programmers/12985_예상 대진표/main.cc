#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b) {
    int answer = 0;

    while (a != b) {
        a = ceil(a / 2.0);
        b = ceil(b / 2.0);
        answer++;
    }
    
    return answer;
}

int main(void) {
    int n = 8;
    int a = 4;
    int b = 6;
    int answer = solution(n, a, b);
    cout << answer << '\n';
    return 0;
}