#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
private:
    void dfs(const vector<string>& arr, int* answer, string s, int depth) {
        if (depth == arr.size()) {
            *answer = max(*answer, static_cast<int>(s.size()));
            return;
        }

        *answer = max(*answer, static_cast<int>(s.size()));

        for (int i = depth; i < arr.size(); i++) {
            string ns = s + arr[i];
            if (unordered_set<char>(ns.begin(), ns.end()).size() == ns.size()) {
                dfs(arr, answer, ns, i + 1);
            }
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
    vector<vector<int>> arr2 = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 }
    };
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