#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int solution(vector<string> sentences, int n) {
    int answer = -1;
    vector<char> v;
    
    for (const string& s : sentences) {
        for (char c : s) {
            if (c != ' ') {
                if (isupper(c)) {
                    v.push_back(tolower(c));
                    v.push_back('#');
                } else {
                    v.push_back(c);
                }
            }
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    vector<bool> mask(v.size(), false);
    for (int i = 0; i < n; i++) {
        mask[i] = true;
    }

    do {
        unordered_set<char> us;
        bool shift = false;
        int score = 0;
        for (int i = 0; i < mask.size(); i++) {
            if (mask[i]) {
                char c = v[i];
                if (c == '#') {
                    shift = true;
                }
                us.insert(c);
            }
        }

        for (const string& s : sentences) {
            string temp = s;
            if (shift) {
                transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            }
            bool flag = true;
            for (char c : temp) {
                if (c != ' ') {
                    if (us.find(c) == us.end()) {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag) {
                int m = count_if(s.begin(), s.end(), ::isupper);
                score += s.size() + m;
            }
        }

        answer = max(answer, score);

    } while (prev_permutation(mask.begin(), mask.end()));

    return answer;
}

int main() {
    vector<string> sentences = { "line in line", "LINE", "in lion" };
    int n = 5;
    int result = solution(sentences, n);
    cout << result << '\n';
	return 0;
}