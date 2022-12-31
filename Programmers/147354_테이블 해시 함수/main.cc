#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    sort(data.begin(), data.end(), [&](const vector<int>& left, const vector<int>& right) {
        if (left[col - 1] == right[col - 1]) {
            return left[0] > right[0];
        }
        return left[col - 1] < right[col - 1];
    });

    for (int i = row_begin - 1; i < row_end; i++) {
        int n = 0;
        for (int j : data[i]) {
            n += j % (i + 1);
        }
        answer ^= n;
    }

    return answer;
}

int main() {
    vector<vector<int>> data = { { 2, 2, 6 }, { 1, 5, 10 }, { 4, 2, 9 }, { 3, 8, 3 } };
    int col = 2;
    int row_begin = 2;
    int row_end = 3;
    int result = solution(data, col, row_begin, row_end);
    cout << result << '\n';
    return 0;
}