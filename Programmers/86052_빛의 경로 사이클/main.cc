#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

const vector<pair<int, int>> direction = {
    { 0, -1 },
    { 1, 0 },
    { 0, 1 },
    { -1, 0 }
};

int cycle(const vector<string>& grid, vector<vector<vector<bool>>>& visited, int x, int y, int d) {
    int len = 0;
    queue<tuple<int, int, int>> q;

    q.push({ x, y, d });

    while (!q.empty()) {
        tuple<int, int, int> t = q.front();
        q.pop();
        int cx = get<0>(t);
        int cy = get<1>(t);
        int cd = get<2>(t);
        visited[cy][cx][cd] = true;
        len++;

        int nd;
        if (grid[cy][cx] == 'S') {
            nd = cd;
        } else if (grid[cy][cx] == 'L') {
            nd = (cd + 1) % direction.size();
        } else if (grid[cy][cx] == 'R') {
            nd = (cd + 3) % direction.size();
        }
        int ny = (cy + direction[nd].second + grid.size()) % grid.size();
        int nx = (cx + direction[nd].first + grid[ny].size()) % grid[ny].size();

        if (!visited[ny][nx][nd]) {
            q.push({ nx, ny, nd });
        }
    }

    return len;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    vector<vector<vector<bool>>> visited(grid.size(), vector<vector<bool>>(grid[0].size(), vector<bool>(4, false)));

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            for (int k = 0; k < direction.size(); k++) {
                if (!visited[i][j][k]) {
                    int c = cycle(grid, visited, j, i, k);
                    answer.push_back(c);
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