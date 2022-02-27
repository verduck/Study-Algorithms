#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(const vector<vector<int>>& graph, vector<bool>& visited, int v) {
    int count = 0;
    queue<int> q;
    q.push(v);

    while (!q.empty()) {
        int c = q.front();
        q.pop();
        visited[c] = true;
        count++;

        for (int n : graph[c]) {
            if (!visited[n]) {
                q.push(n);
            }
        }
    }

    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;

    for (int i = 0; i < wires.size(); i++) {
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> visited(n, false);

        for (int j = 0; j < wires.size(); j++) {
            if (i != j) {
                graph[wires[j][0] - 1].push_back(wires[j][1] - 1);
                graph[wires[j][1] - 1].push_back(wires[j][0] - 1);
            }
        }

        vector<int> counts;
        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i]) {
                int count = bfs(graph, visited, i);
                counts.push_back(count);
            }
        }

        int diff = abs(counts[0] - counts[1]);
        answer = min(answer, diff);
    }

    return answer;
}

int main() {
    int n = 9;
    vector<vector<int>> wires = { { 1,3 },{ 2,3 },{ 3,4 },{ 4,5 },{ 4,6 },{ 4,7 },{ 7,8 },{ 7,9 } };
    int result = solution(n, wires);
    cout << result << '\n';
    return 0;
}