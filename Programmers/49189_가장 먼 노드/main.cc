#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> dijkstra(const vector<vector<int>>& graph, int v) {
    vector<int> dist(graph.size(), INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 

    dist[v] = 0;
    pq.push({ 0, v });

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        for (int n : graph[cur.second]) {
            if (dist[n] > dist[cur.second] + 1) {
                dist[n] = dist[cur.second] + 1;
                pq.push({ dist[n], n });
            }
        }
    }

    return dist;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n, vector<int>());
    for (const vector<int>& v : edge) {
        graph[v[0] - 1].push_back(v[1] - 1);
        graph[v[1] - 1].push_back(v[0] - 1);
    }
    vector<int> dist = dijkstra(graph, 0);
    int m = *max_element(dist.begin(), dist.end());
    for (int i : dist) {
        if (i == m) {
            answer++;
        }
    }
    return answer;
}

int main() { 
    int n = 6;
    vector<vector<int>> vertex = { { 3, 6 }, { 4, 3 }, { 3, 2 }, { 1, 3 }, { 1, 2 }, { 2, 4 }, { 5, 2 } };
    int result = solution(n, vertex);
    cout << result << '\n';
    return 0;
}