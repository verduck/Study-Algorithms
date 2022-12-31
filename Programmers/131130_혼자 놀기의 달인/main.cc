#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(const vector<int>& cards, vector<bool>& visited, int i) {
    int result = 0;
    queue<int> q;
    q.push(cards[i]);
    visited[i] = true;
    result++;

    while (!q.empty()) {
        int j = q.front();
        q.pop();

        if (!visited[j - 1]) {
            q.push(cards[j - 1]);
            visited[j - 1] = true;
            result++;
        }
    }

    return result;
}

int solution(vector<int> cards) {
    int answer = 0;
    vector<bool> visited(cards.size(), false);
    vector<int> scores;

    for (int i = 0; i < cards.size(); i++) {
        if (!visited[i]) {
            scores.push_back(bfs(cards, visited, i));
        }
    }

    sort(scores.begin(), scores.end(), greater<>());

    if (scores.size() >= 2) {
        answer = scores[0] * scores[1];
    }

    return answer;
}

int main() {
    vector<int> cards = { 8,6,3,7,2,5,1,4 };
    int result = solution(cards);
    cout << result << '\n';
    return 0;
}