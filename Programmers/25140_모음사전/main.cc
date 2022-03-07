#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

const vector<char> v = { 'A', 'E', 'I', 'O', 'U' };

bool dfs(const string& word, string& s, int index, int *answer) {
    if (index > v.size()) {
        (*answer)--;
        return false;
    }

    if (s == word) {
        return true;
    }
    
    s += 'A';
    for (int i = 0; i < v.size(); i++) {
        s[index] = v[i];
        (*answer)++;
        if (dfs(word, s, index + 1, answer)) {
            return true;
        }
    }
    s.pop_back();
    return false;
}

int solution(string word) {
    int answer = 0;
    string s;
    dfs(word, s, 0, &answer);
    return answer;
}

/* int solution(string word) {
    int answer = 0;
    const unordered_map<char, int> alphabets = {
        { 'A', 0 },
        { 'E', 1 },
        { 'I', 2 },
        { 'O', 3 },
        { 'U', 4 },
    };
    const int kNumberofAlphabets = alphabets.size();
    int end_of_words = 0;

    for (int i = 1; i <= kNumberofAlphabets; i++) {
        end_of_words += pow(kNumberofAlphabets, i);
    }

    for (int i = 0; i < word.size(); i++) {
        int n = end_of_words / pow(kNumberofAlphabets, i + 1);
        n *= alphabets.at(word[i]);
        answer += ++n;
    }
    return answer;
} */

int main() {
    string word = "EIO";
    int result = solution(word);
    cout << result << '\n';
    return 0;
}