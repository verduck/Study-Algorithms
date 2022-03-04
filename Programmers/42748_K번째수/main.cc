#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (const vector<int>& cmd : commands) {
        vector<int> v(array.begin() + cmd[0] - 1, array.begin() + cmd[1]);
        sort(v.begin(), v.end());
        answer.push_back(v[cmd[2] - 1]);
    }

    return answer;
}

int main() {
    vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> commands = { { 2, 5, 3 }, { 4, 4, 1 }, { 1, 7, 3 } };
    vector<int> answer = solution(array, commands);
    for (int i : answer) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}