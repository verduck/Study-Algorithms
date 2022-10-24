#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
private:
    void dfs(const vector<string>& arr, int* answer, string s, int depth) {
        if (unordered_set<char>(s.begin(), s.end()).size() != s.size()) {
            return;
        }

        *answer = max(*answer, static_cast<int>(s.size()));
        if (depth == arr.size()) {
            return;
        }

        for (int i = depth; i < arr.size(); i++) {
            dfs(arr, answer, s + arr[i], i + 1);
        }
    }
public:
    int maxLength(vector<string>& arr) {
        int answer = 0;
        
        dfs(arr, &answer, string(), 0);

        return answer;
    }
};

void init();

int main() {
    vector<string> arr = {"abcdefghijklmnopqrstuvwxyz"};

    init();

    Solution solution;
    int result = solution.maxLength(arr);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}