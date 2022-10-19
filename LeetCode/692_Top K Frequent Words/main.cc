#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> answer;
        unordered_map<string, int> frequents;

        for (const string& s : words) {
            frequents[s]++;
        }

        vector<pair<string, int>> v(frequents.begin(), frequents.end());
        sort(v.begin(), v.end(), [](const pair<string, int>& left, const pair<string, int>& right) {
            if (left.second == right.second) {
                return left.first < right.first;
            } else {
                return left.second > right.second;
            }
        });

        for (int i = 0; i < k; i++) {
            answer.push_back(v[i].first);
        }

        return answer;
    }
};

void init();

int main() {
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    int k = 2;

    init();

    Solution solution;
    vector<string> result = solution.topKFrequent(words, k);

    for (const string& s : result) {
        cout << s << ' ';
    }
    cout << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}