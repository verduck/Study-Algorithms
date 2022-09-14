#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;
        int buy = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] <= buy) {
                buy = prices[i];
            } else {
                answer = max(answer, prices[i] - buy);
            }
        }

        return answer;
    }
};

void init();

int main() {
    vector<int> prices = { 7, 1, 5, 3, 6, 4 };

    init();

    Solution solution;
    int result = solution.maxProfit(prices);
    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}