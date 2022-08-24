#include <iostream>
#include <vector>

using namespace std;

void init();

class Solution {
public:
    bool isPowerOfThree(int n) {
		if (n == 0) {
			return false;
		} else if (n == 1) {
			return true;
        } else if (n % 3 == 0) {
			return isPowerOfThree(n / 3);
        } else {
			return false;
        }
    }
};

int main() {
	int n = 45;

	init();

	Solution s;
	bool result = s.isPowerOfThree(n);

	cout << boolalpha << result << '\n';
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}