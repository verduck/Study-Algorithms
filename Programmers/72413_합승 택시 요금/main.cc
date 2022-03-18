#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<vector<long long>> floyd_warshall(const vector<vector<pair<int, int>>>& graph) {
    vector<vector<long long>> dist(graph.size(), vector<long long>(graph.size(), INT_MAX));

    for (int i = 0; i < graph.size(); i++) {
        for (const pair<int, int>& p : graph[i]) {
            dist[i][p.first] = min(dist[i][p.first], static_cast<long long>(p.second));
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

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());

    for (const vector<int>& v : fares) {
        graph[v[0] - 1].push_back({ v[1] - 1, v[2] });
        graph[v[1] - 1].push_back({ v[0] - 1, v[2] });
    }

    vector<vector<long long>> fees = floyd_warshall(graph);

    if (fees[s - 1][a - 1] != INT_MAX || fees[s - 1][b - 1] != INT_MAX) {
        answer = fees[s - 1][a - 1] + fees[s - 1][b - 1];
    }

    for (int i = 0; i < n; i++) {
        int fee = fees[s - 1][i];

        if (fees[i][a - 1] != INT_MAX || fees[i][b - 1] != INT_MAX) {
            fee += fees[i][a - 1] + fees[i][b - 1];
            answer = min(answer, fee);
        }
    }
    return answer;
}

int main() {
    int n = 6;
    int s = 4;
    int a = 6;
    int b = 2;
    vector<vector<int>> fares = { { 4, 1, 10 }, { 3, 5, 24 }, { 5, 6, 2 }, { 3, 1, 41 }, { 5, 1, 24 }, { 4, 6, 50 }, { 2, 4, 66 }, { 2, 3, 22 }, { 1, 6, 25 } };
    int result = solution(n, s, a, b, fares);
    cout << result;
    return 0;
}