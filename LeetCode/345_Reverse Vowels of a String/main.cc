#include <iostream>
#include <string>

using namespace std;

void init();

class Solution {
private:
	bool isVowel(char ch) {
		return ch == 'a' || ch =='e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
	}

	int prevVowelIndex(const string& s, int right) {
		while (right > 0) {
			if (isVowel(s[right])) {
				return right;
			} else {
				right--;
			}
		}

		return 0;
	}

public:
    string reverseVowels(string s) {
        string result;
		int left = 0;
		int right = s.size() - 1;

		while (left < s.size()) {
			if (isVowel(s[left]) && left < right) {
				right = prevVowelIndex(s, right);
				char temp = s[left];
				s[left] = s[right];
				s[right] = temp;
				result += s[left];
				left++;
				right--;
			} else {
				result += s[left++];
			}
		}

		return result;
    }
};

int main() {
	string s = "leetcode";

	init();

	Solution solution;
	string result = solution.reverseVowels(s);

	cout << result << '\n';
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}