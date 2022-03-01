#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(gcd(n, m));
    answer.push_back(lcm(n, m));
    return answer;
}

int main() {
    int n = 3;
    int m = 12;
    vector<int> result = solution(n, m);

    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}