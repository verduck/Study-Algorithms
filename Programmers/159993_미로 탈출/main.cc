#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

const vector<pair<int, int>> dirs = {
    { 1, 0 },
    { 0, 1 },
    { -1, 0 },
    { 0, -1 }
};

pair<int, int> find_pos(const vector<string>& maps, char obj) {
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] == obj) {
                return { j, i };
            }
        }
    }

    return { 0, 0 };
}

int find_sortest(const vector<string>& maps, int sx, int sy, char dest) {
    int result = INT_MAX;
    queue<tuple<int, int, int>> q;
    vector<vector<int>> visited(maps.size(), vector<int>(maps[0].size(), INT_MAX));
    q.push({ sx, sy, 0 });
    visited[sy][sx] = 0;

    while (!q.empty()) {
        tuple<int, int, int> t = q.front();
        q.pop();
        int x = get<0>(t);
        int y = get<1>(t);
        int c = get<2>(t);

        if (maps[y][x] == dest) {
            result = min(result, c);
        }

        for (const pair<int, int>& dir : dirs) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            int nc = c + 1;

            if (ny < 0 || ny >= maps.size() || nx < 0 || nx >= maps[ny].size()) {
                continue;
            }

            if (maps[ny][nx] != 'X' && visited[ny][nx] > nc) {
                q.push({ nx, ny, nc });
                visited[ny][nx] = nc;
            }
        }
    }

    return result;
}

int solution(vector<string> maps) {
    int answer = 0;
    pair<int, int> start_pos = find_pos(maps, 'S');

    int distance = find_sortest(maps, start_pos.first, start_pos.second, 'L');

    if (distance == INT_MAX) {
        return -1;
    }

    start_pos = find_pos(maps, 'L');
    answer += find_sortest(maps, start_pos.first, start_pos.second, 'E');

    if (answer == INT_MAX) {
        return -1;
    }

    answer += distance;

    return answer;
}

int main() {
    vector<string> maps = { "SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE" };

    int result = solution(maps);

    cout << result << '\n';
    return 0;
}