#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer(numRows);

        for (int i = 0; i < numRows; i++) {
            answer[i].assign(i + 1, 0);
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    answer[i][j] = 1;
                } else {
                    answer[i][j] = answer[i - 1][j - 1] + answer[i - 1][j];
                }
            }
        }

        return answer;
    }
};

void init();

int main() {
    int numRows = 5;

    init();

    Solution solution;
    vector<vector<int>> result = solution.generate(numRows);
    
    for (const vector<int>& v : result) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}