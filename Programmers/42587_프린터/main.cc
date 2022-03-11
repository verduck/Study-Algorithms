#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq(priorities.begin(), priorities.end());

    for (int i = 0; i < priorities.size(); i++) {
        q.push({ i, priorities[i] });
    }

    while (!q.empty()) {
        int priority = pq.top();
        pair<int, int> p = q.front();
        q.pop();
        if (p.second == priority) {
            answer++;
            if (p.first == location) {
                break;
            }
            pq.pop();
        } else {
            q.push(p);
        }
    }

    return answer;
}

int main() {
    vector<int> priorities = { 1, 1, 9, 1, 1, 1 };
    int location = 0;
    int answer = solution(priorities, location);
    cout << answer << '\n';
    return 0;
}