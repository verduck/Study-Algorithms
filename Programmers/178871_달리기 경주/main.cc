#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer(players.size());
    unordered_map<string, int> player_index;

    for (int i = 0; i < players.size(); i++) {
        player_index[players[i]] = i;
    }

    for (const string& calling : callings) {
        int find_index = player_index[calling];
        string prev_player = players[find_index - 1];
        player_index[prev_player]++;
        player_index[calling]--;
        iter_swap(players.begin() + find_index, players.begin() + find_index - 1);
    }

    answer = players;
    
    return answer;
}

int main() {
    vector<string> players = { "mumu", "soe", "poe", "kai", "mine" };
    vector<string> callings = { "kai", "kai", "mine", "mine" };
    vector<string> result = solution(players, callings);
    for (const string& s : result) {
        cout << s << "\n";
    }
    return 0;
}