#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    template <typename Iterator>
    string join(Iterator begin, Iterator end) {
        string result;
        while (begin != end) {
            result += *begin++;
        }

        return result;
    }
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string string1 = join(word1.begin(), word1.end());
        string string2 = join(word2.begin(), word2.end());

        return string1 == string2;
    }
};

void init();

int main() {
    vector<string> word1 = { "ab", "c" };
    vector<string> word2 = { "a", "bc" };

    init();

    Solution solution;
    bool result = solution.arrayStringsAreEqual(word1, word2);

    cout << boolalpha << result << '\n';
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}