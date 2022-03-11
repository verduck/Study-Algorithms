#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> get_border(const vector<vector<int>>& arr, int x1, int y1, int x2, int y2) {
    deque<int> boarder;
    for (int i = y1; i <= y2; i++) {
        boarder.push_back(arr[x1][i]);
    }

    for (int i = x1 + 1; i <= x2; i++) {
        boarder.push_back(arr[i][y2]);
    }

    for (int i = y2 - 1; i >= y1; i--) {
        boarder.push_back(arr[x2][i]);
    }

    for (int i = x2 - 1; i >= x1 + 1; i--) {
        boarder.push_back(arr[i][y1]);
    }

    return boarder;
}

void change_border(vector<vector<int>>& arr, deque<int> boarder, int x1, int y1, int x2, int y2) {
    for (int i = y1; i <= y2; i++) {
        arr[x1][i] = boarder.front();
        boarder.pop_front();
    }

    for (int i = x1 + 1; i <= x2; i++) {
        arr[i][y2] = boarder.front();
        boarder.pop_front();
    }

    for (int i = y2 - 1; i >= y1; i--) {
        arr[x2][i] = boarder.front();
        boarder.pop_front();
    }

    for (int i = x2 - 1; i >= x1 + 1; i--) {
        arr[i][y1] = boarder.front();
        boarder.pop_front();
    }
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> arr(rows, vector<int>(columns, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            arr[i][j] = i * columns + j + 1;
        }
    }

    for (const vector<int>& v : queries) {
        deque<int> boarder = get_border(arr, v[0] - 1, v[1] - 1, v[2] - 1, v[3] - 1);
        answer.push_back(*min_element(boarder.begin(), boarder.end()));

        boarder.push_front(boarder.back());
        boarder.pop_back();

        change_border(arr, boarder, v[0] - 1, v[1] - 1, v[2] - 1, v[3] - 1);
    }

    return answer;
}

int main() {
    int rows = 6;
    int columns = 6;
    vector<vector<int>> queries = { { 2, 2, 5, 4 }, { 3, 3, 6, 6 }, { 5, 1, 6, 3 } };
    vector<int> result = solution(rows, columns, queries);
    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}