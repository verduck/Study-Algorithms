#include <iostream>
#include <bitset>

using namespace std;

int solution(int n) {
    int ans = 0;
    bitset<32> b(n);

    ans = b.count();

    return ans;
}

int main() {
    int n = 5;
    int result = solution(n);
    cout << result << '\n';
    return 0;
}