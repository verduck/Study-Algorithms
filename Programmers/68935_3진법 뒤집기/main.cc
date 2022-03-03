#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> trit;

    while (n) {
        trit.push_back(n % 3);
        n /= 3;
    }

    for (int i = 0; i < trit.size(); i++) {
        answer += pow(3, trit.size() - 1 - i) * trit[i];
    }

    return answer;
}

int main() {
    int n = 125;
    int answer = solution(n);
    cout << answer << '\n';
    return 0;
}