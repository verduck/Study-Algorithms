#include <iostream>
#include <vector>

using namespace std;

bool check(const vector<vector<bool>>& board, int n, int i, int j) {
    for (int k = 0; k < n; k++) {
        if (board[k][j]) {
            return false;
        }
    }

    for (int k = i, l = j; k >= 0 && l >= 0; k--, l--) {
        if (board[k][l]) {
            return false;
        }
    }

    for (int k = i, l = j; k < n && l < n; k++, l++) {
        if (board[k][l]) {
            return false;
        }
    }

    for (int k = i, l = j; k >= 0 && l < n; k--, l++) {
        if (board[k][l]) {
            return false;
        }
    }

    for (int k = i, l = j; k < n && l >= 0; k++, l--) {
        if (board[k][l]) {
            return false;
        }
    }

    return true;
}

void dfs(vector<vector<bool>>& board, int n, int i, int *answer) {
    if (i == n) {
        (*answer)++;
        return;
    }

    for (int j = 0; j < n; j++) {
        if (check(board, n, i, j)) {
            board[i][j] = true;
            dfs(board, n, i + 1, answer);
            board[i][j] = false;
        }
    }
}

int solution(int n) {
    int answer = 0;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    dfs(board, n, 0, &answer);
    return answer;
}

int main() {
    int n = 4;
    int result = solution(n);
    cout << result << '\n';
    return 0;
}
