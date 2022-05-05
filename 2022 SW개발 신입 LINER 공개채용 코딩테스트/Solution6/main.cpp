#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<string, int, int, int, int> t;

bool check(const t& left, const t& right, int type) {
    if (type == 0) {
        if (get<4>(right) <= get<4>(left)) {
            return true;
        } else {
            return false;
        }
    } else if (type == 1) {
        if (get<4>(right) >= get<4>(left)) {
            return true;
        } else {
            return false;
        }
    }
}

vector<string> solution(vector<string> req_id, vector<vector<int>> req_info) {
    vector<string> answer;
    map<string, pair<int, int>> infos;
    unordered_map<int, t> pendings;

    for (const string& s : req_id) {
        infos.insert({ s, { 0, 0 } });
    }

    for (int i = 0; i < req_info.size(); i++) {
        t req = { req_id[i], i, req_info[i][0], req_info[i][1], req_info[i][2] };
        int type = get<2>(req);

        auto compare = [&](const t& left, const t& right) -> bool {
            int lp = get<4>(left);
            int rp = get<4>(right);
            if (lp == rp) {
                return get<1>(left) > get<1>(right);
            }

            if (type == 0) {
                return lp > rp;
            } else {
                return lp < rp;
            }
        };
        priority_queue<t, vector<t>, decltype(compare)> pq(compare);
        for (auto it = pendings.begin(); it != pendings.end(); it++) {
            if (get<2>(it->second) != type) {
                pq.push(it->second);
            }
        }

        while (!pq.empty() && get<3>(req) > 0 && check(req, pq.top(), type)) {
            t p = pq.top();
            pq.pop();

            int amount = min(get<3>(req), get<3>(p));
            int price = type == 0 ? get<4>(p) : get<4>(req);

            get<3>(req) -= amount;
            get<3>(p) -= amount;


            if (get<3>(p) == 0) {
                pendings.erase(get<1>(p));
            } else {
                pendings[get<1>(p)] = p;
            }

            if (type == 0) {
                infos[get<0>(req)].first += amount;
                infos[get<0>(req)].second -= amount * price;

                infos[get<0>(p)].first -= amount;
                infos[get<0>(p)].second += amount * price;
            } else if (type == 1) {
                infos[get<0>(req)].first -= amount;
                infos[get<0>(req)].second += amount * price;

                infos[get<0>(p)].first += amount;
                infos[get<0>(p)].second -= amount * price;
            }
        }

        if (get<3>(req) > 0) {
            pendings.emplace(i, req);
        }
    }

    for (auto it = infos.begin(); it != infos.end(); it++) {
        string s;
        s += it->first + " ";
        if (it->second.first > 0) {
            s += "+";
        }

        s += to_string(it->second.first) + " ";

        if (it->second.second > 0) {
            s += "+";
        }

        s += to_string(it->second.second);
        answer.push_back(s);
    }
    

    return answer;
}

int main() {
    /*vector<string> req_id = { "William", "Andy", "Rohan", "Rohan", "Louis", "Andy" };
    vector<vector<int>> req_info = { { 1, 7, 20 }, { 0, 10, 10 }, { 1, 10, 40 }, { 1, 4, 25 }, { 0, 5, 11 }, { 0, 20, 30 } };*/
    vector<string> req_id = { "Morgan", "Teo", "Covy", "Covy", "Felix" };
    vector<vector<int>> req_info = { { 0, 10, 50 }, { 1, 35, 70 }, { 0, 10, 30 }, { 0, 10, 50 }, { 1, 11, 40 } };
    vector<string> req = solution(req_id, req_info);
    for (const string& s : req) {
        cout << s << '\n';
    }
	return 0;
}