#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

const vector<pair<int, int>> directions = {
    { 0, 1 },
    { 1, 0 },
    { 0, -1 },
    { -1, 0 }
};

pair<int, int> find_start_position(const vector<string>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'R') {
                return { j, i };
            }
        }
    }

    return { 0, 0 };
}

pair<int, int> move(const vector<string>& board, const pair<int, int>& dir, int x, int y) {
    int dx = x + dir.first;
    int dy = y + dir.second;

    if (dy >= board.size() || dy < 0 || dx >= board[dy].size() || dx < 0 || board[dy][dx] == 'D') {
        return { x, y };
    }

    return move(board, dir, dx, dy);
}

int solution(vector<string> board) {
    int answer = INT_MAX;
    queue<tuple<int, int, int>> q;
    vector<vector<vector<bool>>> visited(board.size(), vector<vector<bool>>(board[0].size(), vector<bool>(directions.size(), false)));
    pair<int, int> pos = find_start_position(board);
    
    q.push({ pos.first, pos.second, 0 });


    while (!q.empty()) {
        tuple<int, int, int> p = q.front();
        q.pop();
        int x = get<0>(p);
        int y = get<1>(p);
        int c = get<2>(p);
        
        if (board[y][x] == 'G') {
            answer = min(answer, c);
        }

        for (int i = 0; i < directions.size(); i++) {
            pair<int, int> np = move(board, directions[i], x, y);
            int nx = np.first;
            int ny = np.second;
            int nd = (i + 2) % directions.size();

            if (!visited[ny][nx][nd]) {
                visited[ny][nx][nd] = true;
                q.push({ nx, ny, c + 1 });
            }
        }
    }

    if (answer == INT_MAX) {
        answer = -1;
    }

    return answer;
}

int main() {
    vector<string> board = {
        "...D..R",
        ".D.G...",
        "....D.D",
        "D....D.",
        "..D...."
    };

    int result = solution(board);

    cout << result << '\n';

    return 0;
}