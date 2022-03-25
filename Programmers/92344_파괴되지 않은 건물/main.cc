#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    const int N = board.size();
    const int M = board[0].size();
    vector<vector<int>> prefix(N + 1, vector<int>(M + 1, 0));

    for (const vector<int>& v : skill) {
        int type = v[0];
        int r1 = v[1];
        int c1 = v[2];
        int r2 = v[3];
        int c2 = v[4];
        int degree = type == 1 ? -v[5] : v[5];

        prefix[r1][c1] += degree;
        prefix[r1][c2 + 1] -= degree;
        prefix[r2 + 1][c1] -= degree;
        prefix[r2 + 1][c2 + 1] += degree;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            prefix[i][j] += prefix[i - 1][j];
        }
    }

    for (int j = 1; j < M; j++) {
        for (int i = 0; i < N; i++) {
            prefix[i][j] += prefix[i][j - 1];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] + prefix[i][j] > 0) {
                answer++;
            }
        }
    }
    return answer;
}