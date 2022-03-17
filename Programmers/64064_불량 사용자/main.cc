#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

void combination(set<set<string>>& banned_list, const vector<vector<string>>& candidates, vector<string>& ban, int depth) {
    set<string> s(ban.begin(), ban.end());
    if (s.size() < depth) {
        return;
    }
    if (candidates.size() == depth) {
        if (s.size() == candidates.size()) {
            banned_list.insert(s);
        }
        return;
    } else {
        vector<string> v = candidates[depth];
        for (int i = 0; i < v.size(); i++) {
            ban[depth] = v[i];
            combination(banned_list, candidates, ban, depth + 1);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<string>> candidates;

    for (const string& ban : banned_id) {
        vector<string> v;
        for (const string& user : user_id) {
            bool is_same = true;
            if (user.size() == ban.size()) {
                for (int i = 0; i < ban.size(); i++) {
                    if (ban.at(i) != '*') {
                        is_same = user.at(i) == ban.at(i);
                        if (!is_same) {
                            break;
                        }
                    }
                }
                if (is_same) {
                    v.push_back(user);
                }
            }
        }
        candidates.push_back(v);
    }

    vector<string> ban(banned_id.size());
    set<set<string>> banned_list;
    combination(banned_list, candidates, ban, 0);
    answer = banned_list.size();

    return answer;
}

int main() {
    vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
    vector<string> banned_id = { "fr*d*", "*rodo", "******", "******" };
    int result = solution(user_id, banned_id);
    cout << result << '\n';
    return 0;
}