#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int sr = left / n;
    int er = right / n;
    int sc = left % n;
    int ec = right % n;

    for (int i = sr; i <= er; i++) {
        int m = i + 1;
        for (int j = 0; j < m; j++) {
            answer.push_back(m);
        }

        for (int j = m + 1; j <= n; j++) {
            answer.push_back(j);
        }
    }

    answer.assign(answer.begin() + sc, answer.end() - (n - ec) + 1);
    return answer;
}

int main() {
    int n = 4;
    long long left = 7;
    long long right = 14;
    vector<int> result = solution(n, left, right);

    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}