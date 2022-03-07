#include <iostream>
#include <string>
#include <vector>

using namespace std;

int check(const vector<vector<int>>& arr, int sx, int sy, int size) {
    int result = arr[sy][sx];
    for (int i = sy; i < sy + size; i++) {
        for (int j = sx; j < sx + size; j++) {
            if (result != arr[i][j]) {
                return -1;
            }
        }
    }

    return result;
}

void quad(const vector<vector<int>>& arr, int sx, int sy, int size, vector<int>& answer) {
    if (size == 1) {
        answer[arr[sy][sx]]++;
        return;
    }
    int i = check(arr, sx, sy, size);
    if (i == -1) {
        int new_size = size / 2;
        quad(arr, sx, sy, new_size, answer);
        quad(arr, sx + new_size, sy, new_size, answer);
        quad(arr, sx, sy + new_size, new_size, answer);
        quad(arr, sx + new_size, sy + new_size, new_size, answer);
    } else {
        answer[i]++;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2);
    quad(arr, 0, 0, arr.size(), answer);
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