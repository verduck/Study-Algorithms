#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<int, int> find_start_pos(const vector<string>& park) {
    for (int i = 0; i < park.size(); i++) {
        for (int j = 0; j < park[i].size(); j++) {
            if (park[i][j] == 'S') {
                return { i, j };
            }
        }
    }

    return { 0, 0 };
}

pair<int, int> get_direction(char op) {
    switch (op) {
    case 'N':
        return { -1, 0 };
    case 'S':
        return { 1, 0 };
    case 'W':
        return { 0, -1 };
    case 'E':
        return { 0, 1 };
    default:
        return { 0, 0 };
    }
}

pair<int, int> move(const vector<string>& park, char op, int n, int x, int y) {
    int nx = x;
    int ny = y;
    pair<int, int> dir = get_direction(op);

    while (n--) {
        nx += dir.second;
        ny += dir.first;

        if (ny < 0 || ny >= park.size() || nx < 0 || nx >= park[ny].size()) {
            return { y, x };
        } else if (park[ny][nx] == 'X') {
            return { y, x };
        }
    }

    return { ny, nx };
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    pair<int, int> pos = find_start_pos(park);

    for (const string& route : routes) {
        char op = route[0];
        int n = route[2] - '0';

        pos = move(park, op, n, pos.second, pos.first);
    }

    answer = { pos.first, pos.second };
    
    return answer;
}

int main() {
    vector<string> park = { "SOO", "OOO", "OOO" };
    vector<string> routes = { "E 2", "S 2", "W 1" };
    vector<int> result = solution(park, routes);
    
    for (int i : result) {
        cout << i << '\n';
    }

    return 0;
}