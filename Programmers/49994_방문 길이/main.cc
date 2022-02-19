#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

const vector<pair<int, int>> dxy = {
    { 0, -1 },
    { 1, 0 },
    { 0, 1 },
    { -1, 0 }
};

const unordered_map<char, int> dir = {
    { 'U', 0 },
    { 'R', 1 },
    { 'D', 2 },
    { 'L', 3 }
};

const unordered_map<char, char> reverse_dir = {
    { 'U', 'D' },
    { 'D', 'U' },
    { 'R', 'L' },
    { 'L', 'R' }
};

int solution(string dirs) {
    int answer = 0;
    vector<vector<vector<bool>>> visited(11, vector<vector<bool>>(11, vector<bool>(4, false)));
    int x = 5;
    int y = 5;

    for (char ch : dirs) {
        int d = dir.at(ch);
        int rd = (d + 2) % 4;
        pair<int, int> p = dxy[d];
        int nx = x + p.first;
        int ny = y + p.second;

        if (nx >= 0 && nx < 11 && ny >= 0 && ny < 11) {
            if (!visited[nx][ny][d]) {
                visited[nx][ny][d] = true;
                visited[x][y][rd] = true;
                answer++;
            }
            x = nx;
            y = ny;
        }

        
    }

    return answer;
}

int main() {
    string dirs = "ULURRDLLU";
    int result = solution(dirs);
    cout << result << '\n';
    return 0;
}