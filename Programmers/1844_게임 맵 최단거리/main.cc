#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const vector<pair<int, int>> direction = {
    { 0, -1 },
    { 1, 0 },
    { 0, 1 },
    { -1, 0 }
};

int bfs(const vector<vector<int>>& maps) {
    vector<vector<int>> visited(maps.size(), vector<int>(maps[0].size(), INT_MAX));
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    visited[0][0] = 0;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        int m = visited[y][x];

        for (const pair<int, int>& d : direction) {
            int nx = x + d.first;
            int ny = y + d.second;
            int nm = m + 1;

            if (ny >= 0 && ny < maps.size() && nx >= 0 && nx < maps[ny].size()) {
                if (maps[ny][nx] && visited[ny][nx] > nm) {
                    visited[ny][nx] = nm;
                    q.push({ nx, ny });
                }
            }
        }
    }

    return visited.back().back();
}

int solution(vector<vector<int>> maps) {
    int answer = bfs(maps);

    answer = answer == INT_MAX ? -1 : answer + 1;
    return answer;
}

int main() {
    vector<vector<int>> maps = { { 1, 0, 1, 1, 1 }, { 1, 0, 1, 0, 1 }, { 1, 0, 1, 1, 1 }, { 1, 1, 1, 0, 1 }, { 0, 0, 0, 0, 1 } };
    int answer = solution(maps);
    cout << answer << '\n';
    return 0;
}