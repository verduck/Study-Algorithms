#include <iostream>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

bool check(const set<tuple<int, int, int>>& s) {
    for (auto it = s.begin(); it != s.end(); it++) {
        int x = get<0>(*it);
        int y = get<1>(*it);
        int a = get<2>(*it);

        if (a) {
            if (s.find({ x, y - 1, 0 }) == s.end() && s.find({ x + 1, y - 1, 0 }) == s.end() && (s.find({ x - 1, y, 1 }) == s.end() || s.find({ x + 1, y, 1 }) == s.end())) {
                return false;
            }
        } else {
            if (y != 0 && s.find({ x, y - 1, 0 }) == s.end() && s.find({ x - 1, y, 1 }) == s.end() && s.find({ x, y, 1}) == s.end()) {
                return false;
            }
        }
    }

    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    set<tuple<int, int, int>> structures;

    for (const vector<int>& v : build_frame) {
        int x = v[0];
        int y = v[1];
        int a = v[2];
        int b = v[3];

        if (b) {
            auto it = structures.insert({ x, y, a });
            if (!check(structures)) {
                structures.erase(it.first);
            }
        } else {
            structures.erase({ x, y, a });
            if (!check(structures)) {
                structures.insert({ x, y, a });
            }
        }
    }

    for (const tuple<int, int, int>& t : structures) {
        answer.push_back({ get<0>(t), get<1>(t), get<2>(t) });
    }

    return answer;
}

int main() {
    int n = 4;
    vector<vector<int>> build_frame = { { 0,0,0,1 },{ 2,0,0,1 },{ 4,0,0,1 },{ 0,1,1,1 },{ 1,1,1,1 },{ 2,1,1,1 },{ 3,1,1,1 },{ 2,0,0,0 },{ 1,1,1,0 },{ 2,2,0,1 } };
    vector<vector<int>> result = solution(n, build_frame);
    for (const vector<int>& v : result) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}