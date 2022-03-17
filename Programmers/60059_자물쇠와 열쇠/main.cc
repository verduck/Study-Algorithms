#include <iostream>
#include <string>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& key) {
    vector<vector<int>> temp(key.size(), vector<int>(key.size(), 0));

    for (int i = 0; i < temp.size(); i++) {
        for (int j = 0; j < temp[i].size(); j++) {
            temp[j][temp.size() - i - 1] = key[i][j];
        }
    }

    key = temp;
}

bool unlock(vector<vector<int>> board, const vector<vector<int>>& key, int x, int y) {
    int padding = key.size() - 1;

    for (int i = y; i < y + key.size(); i++) {
        for (int j = x; j < x + key.size(); j++) {
            board[i][j] += key[i - y][j - x];
        }
    }

    for (int i = padding; i < board.size() - padding; i++) {
        for (int j = padding; j < board.size() - padding; j++) {
            if (board[i][j] != 1) {
                return false;
            }
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int padding = key.size() - 1;
    vector<vector<int>> board(lock.size() + (padding * 2), vector<int>(lock.size() + (padding * 2), 0));

    for (int i = 0; i < lock.size(); i++) {
        for (int j = 0; j < lock.size(); j++) {
            board[i + padding][j + padding] = lock[i][j];
        }
    }

    for (int k = 0; k < 3; k++) {
        for (int i = 0; i <= board.size() - key.size(); i++) {
            for (int j = 0; j <= board[i].size() - key.size(); j++) {
                if (unlock(board, key, j, i)) {
                    return true;
                }
            }
        }

        rotate(key);
    }
    
    return answer;
}

int main() {
    vector<vector<int>> key = { { 0, 0, 0 }, { 1, 0, 0 }, { 0, 1, 1 } };
    vector<vector<int>> lock = { { 1, 1, 1 }, { 1, 1, 0 }, { 1, 0, 1 } };
    bool result = solution(key, lock);
    cout << boolalpha << result << '\n';
    return 0;
}