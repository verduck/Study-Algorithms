#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<vector<pair<int, int>>> Graph;

vector<int> dijkstra(const Graph& g, int s) {
    vector<int> dists(g.size(), INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dists[s] = 0;
    pq.push({ dists[s], s });

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        for (const pair<int, int>& p : g[cur.second]) {
            if (dists[cur.second] + p.first < dists[p.second]) {
                dists[p.second] = dists[cur.second] + p.first;
                pq.push({ dists[p.second], p.second });
            }
        }
    }

    return dists;
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    Graph g(N);

    for (const vector<int>& v : road) {
        g[v[0] - 1].push_back({ v[2], v[1] - 1 });
        g[v[1] - 1].push_back({ v[2], v[0] - 1 });
    }

    vector<int> dists = dijkstra(g, 0);

    answer = count_if(dists.begin(), dists.end(), [&](int i) -> bool {
        return i <= K;
    });

    return answer;
}

int main() {
    int N = 5;
    vector<vector<int>> road = { { 1,2,1 },{ 2,3,3 },{ 5,2,2 },{ 1,4,2 },{ 5,3,1 },{ 5,4,2 } };
    int K = 3;
    int result = solution(N, road, K);
    cout << result << '\n';
    return 0;
}