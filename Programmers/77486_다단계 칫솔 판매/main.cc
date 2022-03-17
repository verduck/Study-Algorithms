#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    unordered_map<string, int> member;
    unordered_map<string, string> parent;

    for (int i = 0; i < enroll.size(); i++) {
        string name = enroll[i];
        string referral_name = referral[i];
        member.insert({ name, 0 });
        parent.insert({ name, referral_name });
    }

    for (int i = 0; i < seller.size(); i++) {
        int price = amount[i] * 100;
        int premium = price * 0.1;
        int profit = price - premium;
        member[seller[i]] += profit;

        string p = parent[seller[i]];
        while (p != "-" && premium != 0) {
            profit = premium - floor(premium * 0.1);
            member[p] += profit;
            p = parent[p];
            premium *= 0.1;
        }
    }

    for (const string& s : enroll) {
        answer.push_back(member[s]);
    }
    return answer;
}

int main() {
    vector<string> enroll = { "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
    vector<string> referral = { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" };
    vector<string> seller = { "young", "john", "tod", "emily", "mary" };
    vector<int> amount = { 12, 4, 2, 5, 10 };
    vector<int> result = solution(enroll, referral, seller, amount);
    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}