#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int get_y(int d, int n) {
    return sqrt((pow(d, 2)) - pow(n, 2));
}

long long solution(int k, int d) {
    long long answer = 0;

    for (int i = 0; i <= d; i += k) {
        int y = get_y(d, i);
        answer += floor(y / k) + 1;
    }

    return answer;
}

int main() {
    int k = 1;
    int d = 5;

    long long result = solution(k, d);
    cout << result << '\n';
    return 0;
}