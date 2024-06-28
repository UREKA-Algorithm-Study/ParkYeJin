#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

bool cmp(pair <int, int> p1, pair <int, int> p2) {
    if(p1.first == p2.first) {
        return p1.second > p2.second;
    }
    else return p1.first > p2.first;
}

int main(int argc, char** argv)
{

    int W, N; // 배낭의 무게, 금속의 종류
    vector <pair<int, int>> v; // 무게당 가격, 금속의 무게 
    
    cin >> W >> N;
    for(int i = 0; i < N; i++){
        int weight, price;
        cin >> weight >> price;
        v.push_back({price, weight});
    }
    sort(v.begin(), v.end(), cmp); // 내림차순

    int res = 0;
    for(int i = 0; i < N; i++){
        if (W >= v[i].second) {
            W -= v[i].second;
            res += v[i].first * v[i].second;
        }
        else {
            res += v[i].first * W;
            break;
        }
    }
    cout << res;
    
   return 0;
}