#include <iostream>
#include <vector>
#include <climits>

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

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> graph(n, vector<int>());

    for (const vector<int>& v : results) {
        graph[v[0] - 1].push_back(v[1] - 1);
    }

    vector<vector<long long>> dist = floyd_warshall(graph);
    
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] == INT_MAX && dist[j][i] == INT_MAX) {
                flag = false;
                break;
            }
        }

        if (flag) {
            answer++;
        }
    }

    return answer;
}

int main() {
    int n = 5;
    vector<vector<int>> results = { { 4, 3 }, { 4, 2 }, { 3, 2 }, { 1, 2 }, { 2, 5 } };
    int result = solution(n, results);
    cout << result << '\n';
    return 0;
}