#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void init();

class Solution {
public:
    vector<string> fizzBuzz(int n) {
		vector<string> answer;

        for (int i = 1; i <= n; i++) {
			if (i % 3 == 0 && i % 5 == 0) {
				answer.push_back("FizzBuzz");
			} else if (i % 3 == 0) {
				answer.push_back("Fizz");
			} else if (i % 5 == 0) {
				answer.push_back("Buzz");
			} else {
				answer.push_back(to_string(i));
			}
		}

		return answer;
    }
};

int main() {
	int n = 15;

	init();

	Solution solution;
	vector<string> result = solution.fizzBuzz(n);

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