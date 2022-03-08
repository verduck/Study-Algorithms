#include <iostream>
#include <string>
#include <vector>

using namespace std;

void TriangleSnail(vector<vector<int>>& triangle, int sx, int sy, int num, int size) {
    if (size <= 0) {
        return;    
    }

    int x = sx;
    int y = sy;
    for (int i = y; i < size + sy; i++) {
        triangle[i][x] = num++;
    }
    y = size + sy - 1;
    x = sx + 1;
    for (int i = x; i < size + sx; i++) {
        triangle[y][i] = num++;
    }
    x = size + sx - 2;
    y = size + sy - 2;
    for (int i = y, j = x; i > sy && j > sx; i--, j--) {
        triangle[i][j] = num++;
    }

    TriangleSnail(triangle, sx + 1, sy + 2, num, size - 3);
}

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> triangle(n);

    for (int i = 0; i < n; i++) {
        triangle[i].assign(i + 1, 0);
    }

    TriangleSnail(triangle, 0, 0, 1, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j<= i; j++) {
            answer.push_back(triangle[i][j]);
        }
    }

    return answer;
}

int main() {
    int n = 6;
    vector<int> result = solution(n);
    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}