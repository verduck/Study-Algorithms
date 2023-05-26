#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> order_map;

        for (int i = 0; i < order.size(); i++) {
            order_map[order[i]] = i;
        }

        return is_sorted(words.begin(), words.end(), [&](const string& left, const string& right) {
            for (int i = 0, j = 0; i < left.size() && j < right.size(); i++, j++) {
                if (left[i] != right[j]) {
                    return order_map[left[i]] < order_map[right[j]];
                }
            }

            return left.size() < right.size();
        });
    }
};

void init();

int main() {
    vector<string> words = { "aa", "a" };
    string order = "abqwertyuioplkjhgfdszxcvnm";

    init();

    Solution solution;
    bool result = solution.isAlienSorted(words, order);

    cout << boolalpha << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}