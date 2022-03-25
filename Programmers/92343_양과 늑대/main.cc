#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(const vector<vector<int>>& tree, const vector<int>& info, vector<int> list, int n, int sheeps, int wolves, int *answer) {
    sheeps += info[n] ^ 1;
    wolves += info[n];
    *answer = max(*answer, sheeps);

    if (sheeps <= wolves) {
        return;
    }

    vector<int> next = list;
    next.insert(next.end(), tree[n].begin(), tree[n].end());
    next.erase(find(next.begin(), next.end(), n));
    for (int i : next) {
        dfs(tree, info, next, i, sheeps, wolves, answer);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    vector<vector<int>> tree(info.size(), vector<int>());

    for (const vector<int>& v : edges) {
        tree[v[0]].push_back(v[1]);
    }

    vector<int> next = { 0 };
    dfs(tree, info, next, 0, 0, 0, &answer);
    return answer;
}

int main() {
    vector<int> info = { 0,0,1,1,1,0,1,0,1,0,1,1 };
    vector<vector<int>> edges = { { 0,1 },{ 1,2 },{ 1,4 },{ 0,8 },{ 8,7 },{ 9,10 },{ 9,11 },{ 4,3 },{ 6,5 },{ 4,6 },{ 8,9 } };
    int result = solution(info, edges);
    cout << result << '\n';
    return 0;
}