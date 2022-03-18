#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> total;
    unordered_map<string, vector<pair<int, int>>> plays_by_genres;

    for (int i = 0; i < genres.size(); i++) {
        string genre = genres[i];
        total[genre] += plays[i];
        plays_by_genres[genre].push_back({ i, plays[i] });
    }

    for (auto it = plays_by_genres.begin(); it != plays_by_genres.end(); it++) {
        sort(it->second.begin(), it->second.end(), [](const pair<int, int>& left, const pair<int, int>& right) {
            if (left.second == right.second) {
                return left.first > right.first;
            }
            return left.second < right.second;
        });
    }

    vector<pair<string, int>> v(total.begin(), total.end());
    sort(v.begin(), v.end(), [](const pair<string, int>& left, const pair<string, int>& right) {
        return left.second > right.second;
    });

    for (const pair<string, int>& p : v) {
        vector<pair<int, int>> pv = plays_by_genres[p.first];

        int i = 0;
        while (!pv.empty() && i < 2) {
            answer.push_back(pv.back().first);
            pv.pop_back();
            i++;
        }
    }

    return answer;
}

int main() {
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };
    vector<int> answer = solution(genres, plays);
    for (int i : answer) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}