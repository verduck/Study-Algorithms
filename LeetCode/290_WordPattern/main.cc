#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> match(26);
	    vector<string> sv = split(s, ' ');

        if (pattern.size() != sv.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); i++) {
            auto it = find(match.begin(), match.end(), sv[i]);
            
            if (it != match.end()) {
                if (pattern[i] - 'a' != distance(match.begin(), it)) {
                    return false;
                }
            }
            match[pattern[i] - 'a'] = sv[i];
            
        }

        for (int i = 0; i < pattern.size(); i++) {
            if (match[pattern[i] - 'a'] != sv[i]) {
                return false;
            }
        }

        return true;
    }

    vector<string> split(const string& s, char delim) {
        vector<string> result;
        stringstream ss(s);
        string temp;

        while (getline(ss, temp, delim)) {
            result.push_back(temp);
        }

        return result;
    }
};

void init();

int main() {
    string pattern;
    string s;

    init();

    cin >> pattern;
    cin.ignore();
    getline(cin, s);

    Solution solution;
    cout << boolalpha << solution.wordPattern(pattern, s) << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}