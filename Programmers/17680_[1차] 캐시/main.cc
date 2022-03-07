#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    unordered_map<string, int> cache;

    for (int i = 0; i < cities.size(); i++) {
        string city;
        transform(cities[i].begin(), cities[i].end(), back_inserter(city), (int(*)(int)) tolower);
        auto it = cache.find(city);

        if (it != cache.end()) {
            it->second = i;
            answer += 1;
        } else {
            if (cache.size() >= cacheSize && !cache.empty()) {
                it = min_element(cache.begin(), cache.end(), [](const pair<string, int>& left, const pair<string, int>& right) {
                    return left.second < right.second;
                });
                cache.erase(it);
            }
            if (cache.size() < cacheSize) {
                cache.insert({ city, i });
            }
            answer += 5;
        }
    }
    return answer;
}

int main(void) {
    int cacheSize = 0;
    vector<string> cities = { "LA", "LA" };
    int answer = solution(cacheSize, cities);
    cout << answer << '\n';
    return 0;
}