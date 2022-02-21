#include <iostream>

using namespace std;

int solution(int n) {
    int ans = 0;
    
    while (n) {
        if (n % 2) {
            ans++;
        }
        n /= 2;
    }

    return ans;
}

int main() {
    int n = 5;
    int result = solution(n);
    cout << result << '\n';
    return 0;
}