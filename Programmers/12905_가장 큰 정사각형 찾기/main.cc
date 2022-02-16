#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool all_zero(const vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[j].size(); j++) {
            if (board[i][j]) {
                return false;
            }
        }
    }

    return true;
}

int solution(vector<vector<int>> board) {
    int answer = 1;

    if (all_zero(board)) {
        return 0;
    }

    for (int i = 1; i < board.size(); i++) {
        for (int j = 1; j < board[i].size(); j++) {
            if (board[i][j] != 0) {
                board[i][j] = min(min(board[i - 1][j], board[i][j - 1]), board[i - 1][j - 1]) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }

    return answer * answer;
}

int main() {
    vector<vector<int>> board = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };
    int result = solution(board);
    cout << result << '\n';
    return 0;
}