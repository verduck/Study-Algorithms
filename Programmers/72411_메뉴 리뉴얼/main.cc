#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int check(const vector<string>& orders, const string& comb) {
    int count = 0;

    for (const string& order : orders) {
        bool is_contain = true;
        for (char c : comb) {
            if (order.find(c) == string::npos) {
                is_contain = false;
                break;
            }
        }
        if (is_contain) {
            count++;
        }
    }

    return count;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<char> menu;
    for (const string& s : orders) {
        for (char c : s) {
            menu.push_back(c);
        }
    }
    sort(menu.begin(), menu.end());
    menu.erase(unique(menu.begin(), menu.end()), menu.end());

    for (int i : course) {
        unordered_map<int, vector<string>> combs;
        vector<bool> mask(menu.size(), false);
        for (int j = 0; j < i; j++) {
            mask[j] = true;
        }

        int max_orders = 0;
        do {
            string comb;
            for (int j = 0; j < mask.size(); j++) {
                if (mask[j]) {
                    comb += menu[j];
                }
            }

            int order_count = check(orders, comb);
            if (order_count >= 2) {
                combs[order_count].push_back(comb);
                max_orders = max(max_orders, order_count);
            }
            
        } while(prev_permutation(mask.begin(), mask.end()));

        move(combs[max_orders].begin(), combs[max_orders].end(), back_inserter(answer));
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main() {
    vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> course = { 2, 3, 4 };
    vector<string> result = solution(orders, course);
    for (const string& s : result) {
        cout << s << ' ';
    }
    cout << '\n';
    return 0;
}