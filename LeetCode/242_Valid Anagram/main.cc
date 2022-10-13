#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> um;

        for (char ch : s) {
            um[ch]++;
        }

        for (char ch : t) {
            um[ch]--;
        }

        for (auto it = um.begin(); it != um.end(); it++) {
            if (it->second != 0) {
                return false;
            }
        }

        return true;
    }
};

void init();

int main() {
    string s = "anagram";
    string t = "nagaram";

    init();

    Solution solution;
    bool result = solution.isAnagram(s, t);
    cout << boolalpha << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}