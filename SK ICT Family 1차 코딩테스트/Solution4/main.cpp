#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<vector<long long>> floyd_warshall(const vector<vector<int>>& graph) {
    vector<vector<long long>> dist(graph.size(), vector<long long>(graph.size(), INT_MAX));

    for (int i = 0; i < graph.size(); i++) {
        for (int j : graph[i]) {
            dist[i][j] = min(dist[i][j], 1LL);
        }
    }

    for (int i = 0; i < graph.size(); i++) {
        dist[i][i] = 0;
    }

    for (int k = 0; k < graph.size(); k++) {
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph.size(); j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return dist;
}

long long solution(int n, vector<vector<int>> edges) {
    long long answer = 0;
    vector<vector<int>> graph(n, vector<int>());

    for (const vector<int>& v : edges) {
        graph[v[0]].push_back(v[1]);
        graph[v[1]].push_back(v[0]);
    }

    vector<vector<long long>> dist = floyd_warshall(graph);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            for (int k = 0; k < n; k++) {
                if (i == k || j == k) {
                    continue;
                }
                if (dist[i][j] == INT_MAX || dist[j][k] == INT_MAX || dist[i][k] == INT_MAX) {
                    continue;
                }
                if (dist[i][j] + dist[j][k] == dist[i][k]) {
                    answer++;
                }
            }
        }
    }

    return answer;
}

int main() {
    int n = 4;
    vector<vector<int>> edges = { { 2, 3 }, { 0, 1 }, { 1, 2 } };
    long long result = solution(n, edges);
    cout << result << '\n';
    return 0;
}