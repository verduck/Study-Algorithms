#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int manhattan_distance(const pair<int, int>& left, const pair<int, int>& right) {
    return abs(left.first - right.first) + abs(left.second - right.second);
}

bool check(const vector<string>& place) {
    vector<pair<int, int>> people;
    for (int i = 0; i < place.size(); i++) {
        for (int j = 0; j < place[i].size(); j++) {
            if (place[i][j] == 'P') {
                people.push_back({ j, i });
            }
        }
    }

    if (people.empty()) {
        return true;
    }

    for (int i = 0; i < people.size() - 1; i++) {
        for (int j = i + 1; j < people.size(); j++) {
            int md = manhattan_distance(people[i], people[j]);
            if (md <= 2) {
                if (md == 1) {
                    return false;
                }
                if (people[i].first == people[j].first) {
                    if (place[people[i].second + 1][people[i].first] != 'X') {
                        return false;
                    }
                } else if (people[i].second == people[j].second) {
                    if (place[people[i].second][people[i].first + 1] != 'X') {
                        return false;
                    }
                } else {
                    if (place[people[i].second][people[j].first] != 'X' || place[people[j].second][people[i].first] != 'X') {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (const vector<string>& place : places) {
        int n = check(place) ? 1 : 0;
        answer.push_back(n);
    }

    return answer;
}

int main() {
    vector<vector<string>> places = { { "POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP" }, { "POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP" }, { "PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX" }, { "OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO" }, { "PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP" } };
    vector<int> result = solution(places);
    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}