#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(const vector<vector<int>>& graph, vector<bool>& visited, int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int n : graph[v]) {
            if (!visited[n]) {
                visited[n] = true;
                q.push(n);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<vector<int>> graph(n, vector<int>());
    vector<bool> visited(n, false);

    for (int i = 0; i < computers.size(); i++) {
        for (int j = 0; j < computers[i].size(); j++) {
            if (computers[i][j]) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(graph, visited, i);
            answer++;
        }
    }

    return answer;
}

int main() { 
    int n = 3;
    vector<vector<int>> computers = { { 1, 1, 0 }, { 1, 1, 0 }, { 0, 0, 1 } };
    int result = solution(n, computers);
    cout << result << '\n';
    return 0;
}