#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

const vector<pair<int, int>> direction = {
    { 0, -1 },
    { 1, 0 },
    { 0, 1 },
    { -1, 0 }
};

int bfs(const vector<string>& grid, vector<vector<vector<bool>>>& visited, int x, int y, int d) {
    int len = 0;
    queue<tuple<int, int, int>> q;
    q.push({ x, y, d });

    while (!q.empty()) {
        tuple<int, int, int> t = q.front();
        q.pop();
        x = get<0>(t);
        y = get<1>(t);
        d = get<2>(t);
        visited[y][x][d] = true;
        len++;

        int nd;
        if (grid[y][x] == 'S') {
            nd = d;
        } else if (grid[y][x] == 'R') {
            nd = (d + 3) % direction.size();
        } else if (grid[y][x] == 'L') {
            nd = (d + 1) % direction.size();
        }

        int ny = (y + direction[nd].second + grid.size()) % grid.size();
        int nx = (x + direction[nd].first + grid[ny].size()) % grid[ny].size();

        if (!visited[ny][nx][nd]) {
            q.push({ nx, ny, nd });
        }
    }


    return len;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    vector<vector<vector<bool>>> visited(grid.size(), vector<vector<bool>>(grid[0].size(), vector<bool>(direction.size(), false)));
    
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            for (int k = 0; k < direction.size(); k++) {
                if (!visited[i][j][k]) {
                    int l = bfs(grid, visited, j, i, k);
                    answer.push_back(l);
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main() {
    vector<string> grid = { "SL","LR" };
    vector<int> result = solution(grid);
    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}