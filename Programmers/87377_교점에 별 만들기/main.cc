#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long llong;

vector<int> meet(const vector<int>& f1, const vector<int>& f2) {
    int x, y;

    llong denominator = f1[0] * f2[1] - f1[1] * f2[0];
    llong x_molecule = f1[1] * f2[2] - f1[2] * f2[1];
    llong y_molecule = f1[2] * f2[0] - f1[0] * f2[2];

    if (denominator == 0) {
        return vector<int>();
    }

    if ((x_molecule % denominator) || (y_molecule % denominator)) {
        return vector<int>();
    }

    x = x_molecule / denominator;
    y = y_molecule / denominator;

    return { x, y };
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<vector<int>> meets;

    int max_y = LONG_MIN;
    int min_y = LONG_MAX;
    int max_x = LONG_MIN;
    int min_x = LONG_MAX;

    for (int i = 0; i < line.size() - 1; i++) {
        for (int j = i + 1; j < line.size(); j++) {
            vector<int> v = meet(line[i], line[j]);
            if (!v.empty()) {
                max_y = max(max_y, v[1]);
                min_y = min(min_y, v[1]);
                max_x = max(max_x, v[0]);
                min_x = min(min_x, v[0]);
                meets.push_back(v);
            }
        }
    }

    answer.assign(max_y - min_y + 1, string(max_x - min_x + 1, '.'));

    for (const vector<int>& v : meets) {
        int x = abs(min_x - v[0]);
        int y = abs(max_y - v[1]);
        answer[y][x] = '*';
    }
    
    return answer;
}

int main() {
    vector<vector<int>> line = { { 2, -1, 4 }, { -2, -1, 4 }, { 0, -1, 1 }, { 5, -8, -12 }, { 5, 8, 12 } };
    vector<string> result = solution(line);
    for (const string& s : result) {
        cout << s << '\n';
    }
    return 0;
}