#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>

using namespace std;

const vector<pair<int, int>> d = {
    { 0, 0 },
    { 1, 0 },
    { 0, 1 },
    { 1, 1 }
};

bool is_same_blocks(const vector<string>& board, int x, int y) {
    for (const pair<int, int>& p : d) {
        int nx = x + p.first;
        int ny = y + p.second;

        if (ny >= 0 && ny < board.size() && nx >= 0 && nx < board[ny].size()) {
            if (board[y][x] != board[ny][nx]) {
                return false;
            }
        }
    }

    return true;
}

set<pair<int, int>> search(const vector<string>& board) {
    set<pair<int, int>> result;

    for (int i = 0; i < board.size() - 1; i++) {
        for (int j = 0; j < board[i].size() - 1; j++) {
            if (board[i][j] != ' ' && is_same_blocks(board, j, i)) {
                for (const pair<int, int>& p : d) {
                    result.insert({ j + p.first, i + p.second });
                }
            }
        }
    }

    return result;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while (true) {
        set<pair<int, int>> sames = search(board);
        if (sames.empty()) {
            break;
        }
        answer += sames.size();

        for (const pair<int, int>& p : sames) {
            board[p.second][p.first] = ' ';
        }

        for (int x = 0; x < n; x++) {
            stack<char> st;
            for (int y = 0; y < m; y++) {
                if (board[y][x] != ' ') {
                    st.push(board[y][x]);
                }
            }

            for (int y = m - 1; y >= 0; y--) {
                if (!st.empty()) {
                    board[y][x] = st.top();
                    st.pop();
                } else {
                    board[y][x] = ' ';
                }
            }
        }
    }
    return answer;
}

int main(void) {
    int m = 6;
    int n = 6;
    vector<string> board = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
    int answer = solution(m, n, board);
    cout << answer << '\n';
    return 0;
}