#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int bfs(const vector<vector<int>>& graph, vector<bool>& visited, int v) {
    int count = 0;
    queue<int> q;

    q.push(v);

    while (!q.empty()) {
        v = q.front();
        q.pop();
        visited[v] = true;
        count++;

        for (int n : graph[v]) {
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

        vector<int> v;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int count = bfs(graph, visited, j);
                v.push_back(count);
            }
        }

        answer = min(answer, abs(v[0] - v[1]));
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