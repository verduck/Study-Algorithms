#include <iostream>
#include <vector>

using namespace std;

void init();

class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
		for (int i = 0; i < s.size() / 2; i++) {
			temp = s[i];
			s[i] = s[s.size() - i - 1];
			s[s.size() - i - 1] = temp;
		}

    }
};

int main() {
	vector<char> s = { 'h', 'e', 'l', 'l', 'o' };

	init();

	Solution solution;
	solution.reverseString(s);

	for (char ch: s) {
		cout << ch << ' ';
	}
	cout << '\n';
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}