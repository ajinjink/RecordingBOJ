#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

bool compare2(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, vector<pair<int, int>>> m; // 장르, cnt, num
    map<string, int> total; // 해당 장르 총 재생 횟수
    
    for (int i = 0; i < genres.size(); i++) {
        if (total.find(genres[i]) == total.end()) {
            total[genres[i]] = 0;
        }
        total[genres[i]] += plays[i];
        m[genres[i]].push_back({plays[i], i});
    }
    vector<pair<string, int>> cnt(total.begin(), total.end()); // 장르, 총 재생횟수
    sort(cnt.begin(), cnt.end(), compare); // 재생횟수 내림차순
    
    vector<int> res;
    for (pair<string, int> g : cnt) {
        vector<pair<int, int>> p = m[g.first];
        sort(p.begin(), p.end(), compare2); // 재생횟수 내림차순, 곡 번호 오름차순
        if (p.size() == 1) res.push_back(p[0].second);
        else if (p.size() >= 2) {
            res.push_back(p[0].second);
            res.push_back(p[1].second);
        }
    }
    return res;
}