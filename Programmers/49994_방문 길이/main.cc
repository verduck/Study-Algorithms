#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

const unordered_map<char, pair<int, int>> direction = {
    { 'U', { 0, -1 } },
    { 'D', { 0, 1 } },
    { 'R', { 1, 0 } },
    { 'L', { -1, 0 } }
};

const unordered_map<char, char> reverse_direction = {
    { 'U', 'D' },
    { 'D', 'U' },
    { 'R', 'L' },
    { 'L', 'R' }
};

int solution(string dirs) {
    int answer = 0;
    vector<vector<unordered_map<char, bool>>> visited(11, vector<unordered_map<char, bool>>(11, unordered_map<char, bool>()));
    pair<int, int> pos = { 5, 5 };
    for (const char d : dirs) {
        int x = pos.first;
        int y = pos.second;
        int nx = x + direction.at(d).first;
        int ny = y + direction.at(d).second;
        int rd = reverse_direction.at(d);

        if (nx >= 0 && nx < 11 && ny >= 0 && ny < 11) {
            if (!visited[x][y][d]) {
                visited[x][y][d] = true;
                visited[nx][ny][rd] = true;
                answer++;
            }
            pos = { nx, ny };
        }
    }
    return answer;
}

int main() {
    string dirs = "LULLLLLLU";
    int result = solution(dirs);
    cout << result << '\n';
    return 0;
}