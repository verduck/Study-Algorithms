#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

const vector<pair<int, int>> direction = {
    { 0, -1 },
    { 1, 0 },
    { 0, 1 },
    { -1, 0 }
};

int cycle(const vector<string>& grid, int sx, int sy, int d) {
    int len = 0;
    queue<tuple<int, int, int>> q;
    vector<vector<vector<bool>>> visited(grid.size(), vector<vector<bool>>(grid[0].size(), vector<bool>(4, false)));
    
    while (!q.empty()) {
        tuple<int, int, int> t = q.front();
        q.pop();
        int cx = get<0>(t);
        int cy = get<1>(t);
        int cd = get<2>(t);
    }
    
    return -1;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            for (int k = 0; k < direction.size(); k++) {
                cycle(grid, j, i, k);
            }
        }
    }
    return answer;
}

int main() {
    vector<string> grid = { "SL", "LR" };
    vector<int> result = solution(grid);
    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}