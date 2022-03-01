#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    while (n) {
        answer.push_back(n % 10);
        n /= 10;
    }
    return answer;
}

int main() {
    long long n = 12345;
    vector<int> result = solution(n);
    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}