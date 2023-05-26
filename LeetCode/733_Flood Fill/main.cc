#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    const vector<pair<int, int>> dir = {
        { 0, -1 },
        { 1, 0 },
        { 0, 1 },
        { -1, 0 }
    };
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        int prevColor = image[sr][sc];
        image[sr][sc] = color;
        q.push({sr, sc });

        while (!q.empty()) {
            pair<int, int> cp = q.front();
            q.pop();
            int cr = cp.first;
            int cc = cp.second;

            for (int i = 0; i < dir.size(); i++) {
                int nr = cr + dir[i].first;
                int nc = cc + dir[i].second;

                if (nr < 0 || nr >= image.size() || nc < 0 || nc >= image[nr].size() || visited[nr][nc] || image[nr][nc] != prevColor) {
                    continue;
                }

                image[nr][nc] = color;
                visited[nr][nc] = true;
                q.push({ nr, nc });
            }
        }

        return image;
    }
};

void init();

int main() {
    vector<vector<int>> image = { { 1, 1, 1 }, { 1, 1, 0 }, { 1, 0, 1 } };
    int sr = 1;
    int sc = 1;
    int color = 2;

    init();

    Solution solution;
    vector<vector<int>> result = solution.floodFill(image, sr, sc, color);

    for (const vector<int>& v : result) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}