#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct compare {
    bool operator()(const pair<int, int>& left, const pair<int, int>& right) {
        if (left.second == right.second) {
            return left.first > right.first;
        }
        return left.second > right.second;
    }
};


int solution(vector<vector<int>> targets) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

    for (const vector<int>& target : targets) {
        pq.push({ target[0], target[1] });
    }

    int last = 0;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (p.first >= last) {
            answer++;
            last = p.second;
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> targets = { { 4, 5 }, { 4, 8 }, { 10, 14 }, { 11, 13 }, { 5, 12 }, { 3, 7 }, { 1, 4 } };

    int result = solution(targets);

    cout << result << '\n';
    return 0;
}