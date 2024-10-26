#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

// 고유번호, 재생
bool cmp(pair <int, int> &p1, pair <int, int> &p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    // 장르 이름, 장르 횟수
    map <string, int> m;
    for(int i = 0; i < genres.size(); i++){
        m[genres[i]] += plays[i];
    }
    
    // 장르 횟수, 장르 이름
    vector <pair <int, string>> v;
    for(auto iter : m){
        v.push_back({iter.second, iter.first});
    }
    // 장르 횟수로 내림차순
    sort(v.rbegin(), v.rend());
    
    // 장르별로 
    for(auto iter: v) {
        vector <pair <int, int>> res; // 고유번호, 재생
        for(int i = 0; i < genres.size(); i++){
            if (iter.second == genres[i]) {
                res.push_back({i, plays[i]});
            }
        }
        sort(res.begin(), res.end(), cmp);
        
        int cnt = 0;
        for(auto r: res) {
            answer.push_back(r.first);
            cnt++;
            if (cnt == 2) break;
        }
    }

    
    return answer;
}