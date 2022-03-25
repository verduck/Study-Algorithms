#include <iostream>
#include <vector>

using namespace std;

void hanoi(vector<vector<int>>& answer, int n, int from, int by, int to) {
    if (n == 0) {
        return;
    }
    hanoi(answer, n - 1, from, to, by);
    answer.push_back({ from, to });
    hanoi(answer, n - 1, by, from, to);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(answer, n, 1, 2, 3);
    return answer;
}

int main() {
    int n = 2;
    vector<vector<int>> result = solution(n);

    for (const vector<int>& v : result) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}