#include <iostream>

using namespace std;

void init();

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
**/
int guess(int num) {
	int pick = 6;
	if (num > pick) {
		return -1;
	} else if (num < pick) {
		return 1;
	} else {
		return 0;
	}
}

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
		int right = n;

		while (left <= right) {
			long mid = (static_cast<long>(left) + right) / 2;

			int result = guess(mid);

			if (result == -1) {
				right = mid - 1;
			} else if (result == 1) {
				left = mid + 1;
			} else {
				return mid;
			}
		}

		return left;
    }
};

int main() {
	int n = 10;

	init();

	Solution solution;
	int result = solution.guessNumber(n);

	cout << result << '\n';
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}