#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;

    for (int i : moves) {
        int j = 0;
        for (j = 0; j < board.size(); j++) {
            if (board[j][i - 1]) {
                break;
            }
        }

        if (j < board.size()) {
            int n = board[j][i - 1];
            board[j][i - 1] = 0;
            if (st.empty() || n != st.top()) {
                st.push(n);
            } else if (n == st.top()) {
                st.pop();
                answer += 2;
            }
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> board = { { 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 3 }, { 0, 2, 5, 0, 1 }, { 4, 2, 4, 4, 2 }, { 3, 5, 1, 3, 1 } };
    vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };
    int answer = solution(board, moves);
    cout << answer << '\n';
    return 0;
}