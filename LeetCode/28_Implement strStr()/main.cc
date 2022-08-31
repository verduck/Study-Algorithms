#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.size(); i++) {
            int j;
            for (j = 0; j < needle.size(); j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }

            if (j == needle.size()) {
                return i;
            }
        }
        return -1;
    }
};

void init();

int main() {
    string haystack = "abc";
    string needle = "c";

    init();

    Solution solution;
    int result = solution.strStr(haystack, needle);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}