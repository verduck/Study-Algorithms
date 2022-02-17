#include <iostream>
#include <string>
#include <vector>

using namespace std;

int CheckArr(const vector<vector<int>>& arr, int col, int row, int size) {
    int result = arr[col][row];
    for (int i = col; i < col + size; i++) {
        for (int j = row; j < row + size; j++) {
            if (result != arr[i][j]) {
                return -1;
            }
        }
    }

    return result;
}

void Quad(const vector<vector<int>>& arr, int col, int row, int size, vector<int>& answer) {
    if (size == 1) {
        answer[arr[col][row]]++;
        return;
    }

    int check = CheckArr(arr, col, row, size);
    if (check == -1) {
        int new_size = size / 2;
        Quad(arr, col, row, new_size, answer);
        Quad(arr, col + new_size, row, new_size, answer);
        Quad(arr, col, row + new_size, new_size, answer);
        Quad(arr, col + new_size, row + new_size, new_size, answer);
    } else {
        answer[check]++;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    Quad(arr, 0, 0, arr.size(), answer);
    return answer;
}

int main() {
    vector<vector<int>> arr = { { 1, 1, 0, 0 }, { 1, 0, 0, 0 }, { 1, 0, 0, 1 }, { 1, 1, 1, 1 } };
    vector<int> result = solution(arr);
    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}