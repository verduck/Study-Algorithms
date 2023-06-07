#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int left = n + 1;
    priority_queue<int> pq(section.begin(), section.end());

    while (!pq.empty()) {
        int right = pq.top();
        pq.pop();

        if (left <= right) {
            continue;
        }

        answer++;
        left = right - m + 1;
    }

    return answer;
}

int main() {
    int n = 4;
    int m = 1;
    vector<int> section = { 1, 2, 3, 4 };

    int result = solution(n, m, section);

    cout << result << '\n';
    return 0;
}