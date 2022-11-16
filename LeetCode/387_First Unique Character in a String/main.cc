#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void init();

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, vector<int>> history;

		for (int i = 0; i < s.size(); i++) {
			history[s[i]].push_back(i);
		}

		for (char ch: s) {
			if (history[ch].size() == 1) {
				return history[ch][0];
			}
		}

		return -1;
    }
};

int main() {
	string s = "leetcode";

	init();

	Solution solution;
	int result = solution.firstUniqChar(s);

	cout << result << '\n';
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}