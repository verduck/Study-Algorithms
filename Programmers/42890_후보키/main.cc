#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool CheckMinimality(const vector<int>& candidates, int bit) {
    for (int i : candidates) {
        if ((i & bit) == i) {
            return false;
        }
    }

    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<int> candidates;
    int row_size = relation.size();
    int col_size = relation[0].size();

    for (int i = 1; i < (1 << col_size); i++) {
        set<vector<string>> candidate;
        for (int j = 0; j < row_size; j++) {
            vector<string> tuple;
            for (int k = 0; k < col_size; k++) {
                if (i & (1 << k)) {
                    tuple.push_back(relation[j][k]);
                }
            }
            candidate.insert(tuple);
        }
        if (candidate.size() == row_size && CheckMinimality(candidates, i)) {
            candidates.push_back(i);
        }
    }

    answer = candidates.size();

    return answer;
}

int main() { 
    vector<vector<string>> relation = { { "100","ryan","music","2" },{ "200","apeach","math","2" },{ "300","tube","computer","3" },{ "400","con","computer","4" },{ "500","muzi","music","3" },{ "600","apeach","music","2" } };
    int result = solution(relation);
    cout << result << '\n';
    return 0;
}