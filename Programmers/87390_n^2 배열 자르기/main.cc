#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int start_row = left / n;
    int start_col = left % n;

    int end_row = right / n;
    int end_col = right % n;

    for (int i = start_row; i <= end_row; i++) {
        int m = i + 1;
        for (int j = 0; j < m; j++) {
            answer.push_back(m);
        }
        for (int j = m + 1; j <= n; j++) {
            answer.push_back(j);
        }
    }

    answer.assign(answer.begin() + start_col, answer.end() - (n - end_col) + 1);

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