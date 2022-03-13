#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const vector<pair<int, int>> direction = {
    { 0, -1 },
    { 1, 0 },
    { 0, 1 },
    { -1, 0 }  
};

int bfs(const vector<vector<int>>& picture, vector<vector<bool>>& visited, int x, int y, int c) {
    int count = 0;
    queue<pair<int, int>> q;

    q.push({ x, y });
    visited[y][x] = true;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        count++;

        for (const pair<int, int>& p : direction) {
            int nx = x + p.first;
            int ny = y + p.second;

            if (ny >= 0 && ny < picture.size() && nx >= 0 && nx < picture[ny].size()) {
                if (picture[ny][nx] == c && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    q.push({ nx, ny });
                }
            }
        }
    }

    return count;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] && !visited[i][j]) {
                int count = bfs(picture, visited, j, i, picture[i][j]);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, count);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main() {
    int m = 6;
    int n = 4;
    //vector<vector<int>> picture = { { 1, 1, 1, 0 }, { 1, 2, 2, 0 }, { 1, 0, 0, 1 }, { 0, 0, 0, 1 }, { 0, 0, 0, 3 }, { 0, 0, 0, 3 } };
    vector<vector<int>> picture = { { 1, 1, 1, 0 }, { 1, 1, 1, 0 }, { 0, 0, 0, 1 }, { 0, 0, 0, 1 }, { 0, 0, 0, 1 }, { 0, 0, 0, 1 } };
    vector<int> answer = solution(m, n, picture);
    for (int i : answer) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}