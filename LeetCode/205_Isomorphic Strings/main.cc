#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> ms;
        unordered_map<char, char> mt;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (ms.find(s[i]) == ms.end() && mt.find(t[i]) == mt.end()) {
                ms[s[i]] = t[i];
                mt[t[i]] = s[i];
            } else {
                if (ms[s[i]] != t[i] || mt[t[i]] != s[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};

void init();

int main() {
    string s = "egg";
    string t = "add";

    init();

    Solution solution;
    bool result = solution.isIsomorphic(s, t);

    cout << boolalpha << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}