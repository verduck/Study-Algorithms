#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int n = x;
    int m = 0;

    while (n) {
        m += n % 10;
        n /= 10;
    }

    answer = !(x % m);
    return answer;
}

int main() {
    int x = 11;
    bool result = solution(x);

    cout << boolalpha << result << '\n';
    return 0;
}