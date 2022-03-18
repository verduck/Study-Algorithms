#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

bool dfs(unordered_map<string, multimap<string, bool>>& graph, vector<string>& route, const string& src, int tickets, vector<string>& answer) {
    route.push_back(src);
    if (route.size() == tickets) {
        for (auto it = graph[src].begin(); it != graph[src].end(); it++) {
            if (!it->second) {
                route.push_back(it->first);
            }
        }
        answer = route;
        return true;
    }

    for (auto it = graph[src].begin(); it != graph[src].end(); it++) {
        if (!it->second) {
            it->second = true;
            if (dfs(graph, route, it->first, tickets, answer)) {
                return true;
            }
            it->second = false;
        }
    }

    route.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    unordered_map<string, multimap<string, bool>> graph;

    for (const vector<string>& v : tickets) {
        graph[v[0]].insert({ v[1], false });
    }

    vector<string> v;

    dfs(graph, v, "ICN", tickets.size(), answer);

    return answer;
}

int main() { 
    vector<vector<string>> tickets = { { "ICN", "SFO" }, { "ICN", "ATL" }, { "SFO", "ATL" }, { "ATL", "ICN" }, { "ATL","SFO" } };
    vector<string> result = solution(tickets);
    for (const string& s : result) {
        cout << s << ' ';
    }
    cout << '\n';
    return 0;
}