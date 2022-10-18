#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    string count(int n, string s) {
        if (n <= 1) {
            return s;
        }

        return count(n - 1, say(s));
    }

    string say(const string& s) {
        string result;
        int n = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1]) {
                result += to_string(n);
                result += s[i - 1];
                n = 1;
            } else {
                n++;
            }
        }
        result += to_string(n);
        result += s[s.size() - 1];

        return result;
    }
public:
    string countAndSay(int n) {
        return count(n, "1");
    }
};

void init();

int main() {
    int n = 4;

    init();

    Solution solution;
    string result = solution.countAndSay(n);

    cout << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}