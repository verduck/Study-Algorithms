#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> meet(const vector<int>& f1, const vector<int>& f2) {
    long x_numerator = static_cast<long>(f1[1]) * f2[2] - static_cast<long>(f1[2]) * f2[1];
    long x_denominator = static_cast<long>(f1[0]) * f2[1] - static_cast<long>(f1[1]) * f2[0];
    long y_numerator = static_cast<long>(f1[2]) * f2[0] - static_cast<long>(f1[0]) * f2[2];
    long y_denominator = static_cast<long>(f1[0]) * f2[1] - static_cast<long>(f1[1]) * f2[0];

    if (x_denominator == 0 || y_denominator == 0) {
        return vector<int>();
    }

    double x = x_numerator / x_denominator;
    double y = y_numerator / y_denominator;

    if (!(x_numerator % x_denominator) && !(y_numerator % y_denominator)) {
        return { static_cast<int>(x), static_cast<int>(y) };
    }

    return vector<int>();
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<vector<int>> meets;
    int max_x = INT_MIN;
    int min_x = INT_MAX;
    int max_y = INT_MIN;
    int min_y = INT_MAX;

    for (int i = 0; i < line.size() - 1; i++) {
        for (int j = i + 1; j < line.size(); j++) {
            vector<int> m = meet(line[i], line[j]);
            if (!m.empty()) {
                meets.push_back(m);
                max_x = max(max_x, m[0]);
                min_x = min(min_x, m[0]);
                max_y = max(max_y, m[1]);
                min_y = min(min_y, m[1]);
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
    vector<vector<int>> line = { { 0, 1, -1 }, { 1, 0, -1 }, { 1, 0, 1 } };
    vector<string> result = solution(line);
    for (const string& s : result) {
        cout << s << '\n';
    }
    return 0;
}