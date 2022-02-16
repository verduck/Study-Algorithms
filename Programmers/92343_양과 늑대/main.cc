#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(const vector<vector<int>>& tree, const vector<int>& info, vector<bool>& visited, int cur, int *sheeps, int *wolves, int *answer) {
    *sheeps += (info[cur] ^ 1);
    *wolves += info[cur];

    if (*sheeps == *wolves) {
        *answer = max(*answer, *sheeps);
        return;
    }

    if (visited[cur]) {
        return;
    }
    visited[cur] = true;

    for (int next : tree[cur]) {
        dfs(tree, info, visited, next, sheeps, wolves, answer);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    vector<vector<int>> tree(info.size(), vector<int>());
    vector<bool> visited(info.size(), false);

    for (const vector<int>& v : edges) {
        tree[v[0]].push_back(v[1]);
    }

    visited[0] = true;
    int sheeps = 0;
    int wolves = 0;
    dfs(tree, info, visited, 0, &sheeps, &wolves, &answer);

    return answer;
}

int main() {
    vector<int> info = { 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1 };
    vector<vector<int>> edges = { { 0, 1 }, { 1, 2 }, { 1, 4 }, { 0, 8 }, { 8, 7 }, { 9, 10 }, { 9, 11 }, { 4, 3 }, { 6, 5 }, { 4, 6 }, { 8, 9 } };
    int result = solution(info, edges);
    cout << result << '\n';
    return 0;
}