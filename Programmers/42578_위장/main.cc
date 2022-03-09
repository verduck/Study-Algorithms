#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, vector<string>> um_clothes;

    for (const vector<string>& v : clothes) {
        um_clothes[v[1]].push_back(v[0]);
    }

    for (const pair<string, vector<string>>& p : um_clothes) {
        answer *= p.second.size() + 1;
    }

    return answer - 1;
}

int main() {
    vector<vector<string>> clothes = { { "yellowhat", "headgear" }, { "bluesunglasses", "eyewear" }, { "green_turban", "headgear" } };
    int answer = solution(clothes);
    cout << answer << '\n';
    return 0;
}