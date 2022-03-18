#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <tuple>

using namespace std;

vector<pair<int, int>> direction = {
    { 1, 0 },
    { 0, 1 },
    { -1, 0 },
    { 0, -1 }  
};

int solution(vector<vector<int>> board) {
    int answer = INT_MAX;
    vector<vector<vector<int>>> cost(board.size(), vector<vector<int>>(board.size(), vector<int>(direction.size(), INT_MAX)));
    queue<tuple<int, int, int, int>> q;
    q.push({ 0, 0, -1, 0 });
    for (int i = 0; i < direction.size(); i++) {
        cost[0][0][i] = 0;
    }

    while (!q.empty()) {
        tuple<int, int, int, int> r = q.front();
        q.pop();
        int x = get<0>(r);
        int y = get<1>(r);
        int d = get<2>(r);
        int c = get<3>(r);

        for (int i = 0; i < direction.size(); i++) {
            int nx = x + direction[i].first;
            int ny = y + direction[i].second;
            int nd = i;
            int nc = c + 100;
            if (d != -1 && d != nd) {
                nc += 500;
            }

            if (ny >= 0 && ny < board.size() && nx >= 0 && nx < board[ny].size() && !board[ny][nx]) {
                if (cost[ny][nx][nd] >= nc) {
                    cost[ny][nx][nd] = nc;
                    q.push({ nx, ny, nd, nc });
                }
            }
        }
    }

    for (int i = 0; i < direction.size(); i++) {
        answer = min(answer, cost[board.size() - 1][board.size() - 1][i]);
    }

    return answer;
}

int main() {
    vector<vector<int>> board = { { 0,0,0,0,0,0,0,1 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,1,0,0 },{ 0,0,0,0,1,0,0,0 },{ 0,0,0,1,0,0,0,1 },{ 0,0,1,0,0,0,1,0 },{ 0,1,0,0,0,1,0,0 },{ 1,0,0,0,0,0,0,0 } };
    int result = solution(board);
    cout << result << '\n';
    return 0;
}