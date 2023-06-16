#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const vector<pair<int, int>> dirs = {
    { 1, 0 },
    { 0, 1 },
    { -1, 0 },
    { 0, -1 }
};

int calculate_days(const vector<string>& maps, vector<vector<bool>>& visited, int x, int y) {
    int result = 0;
    queue<pair<int, int>> q;

    q.push({ x, y });
    visited[y][x] = true;

    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        result += maps[p.second][p.first] - '0';

        for (const pair<int, int>& d : dirs) {
            int nx = p.first + d.first;
            int ny = p.second + d.second;

            if (ny < 0 || ny >= maps.size() || nx < 0 || nx >= maps[ny].size()) {
                continue;
            }
            if (maps[ny][nx] != 'X' && !visited[ny][nx]) {
                q.push({ nx, ny });
                visited[ny][nx] = true;
            }
        }
    }

    return result;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] != 'X' && !visited[i][j]) {
                answer.push_back(calculate_days(maps, visited, j, i));
            }
        }
    }
    sort(answer.begin(), answer.end());

    if (answer.empty()) {
        answer.push_back(-1);
    }
    return answer;
}

int main() {
    vector<string> maps = {
        "X591X","X1X5X","X231X", "1XXX1"
    };

    vector<int> result = solution(maps);

    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}