#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool check(const string& left, const string& right) {
    int diff_count = 0;

    for (int i = 0; i < left.size(); i++) {
        if (left[i] != right[i]) {
            diff_count++;
        }
    }

    return diff_count == 1;
}

void dfs(string begin, const string& target, const vector<string>& words, vector<bool>& visited, int depth, int *answer) {
    if (depth >= words.size()) {
        return;
    }

    if (begin == target) {
        *answer = min(*answer, depth);
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        if (check(begin, words[i]) && !visited[i]) {
            visited[i] = true;
            dfs(words[i], target, words, visited, depth + 1, answer);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = INT_MAX;
    vector<bool> visited(words.size(), false);
    dfs(begin, target, words, visited, 0, &answer);
    return answer == INT_MAX ? 0 : answer;
}

int main() { 
    string begin = "hit";
    string target = "cog";
    vector<string> words = { "hot", "dot", "dog", "lot", "log" };
    int result = solution(begin, target, words);
    cout << result << '\n';
    return 0;
}