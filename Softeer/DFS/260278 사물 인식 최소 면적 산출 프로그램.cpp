#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, K;

vector<vector<pair<int, int>>> v;

int res = 4000001;

void dfs(int color, int maxX, int maxY, int minX, int minY){
    if (color == K + 1) {
        res = min(res, abs(maxX-minX) * abs(maxY-minY));
        return;
    }

    for(int i = 0; i < v[color].size(); i++){
        int maxNX = max(maxX, v[color][i].first);
        int maxNY = max(maxY, v[color][i].second);
        int minNX = min(minX, v[color][i].first);
        int minNY = min(minY, v[color][i].second);
        if (abs(maxNX-minNX) * abs(maxNY-minNY) < res) {
            dfs(color + 1, maxNX, maxNY, minNX, minNY);
        }
    }
}

int main(int argc, char** argv)
{
    cin >> N >> K;
    v.resize(K + 1);
    
    for(int i = 0; i < N; i++){
        int x, y, k;
        cin >> x >> y >> k;
        v[k].push_back({x, y});
    }
    // color, maxX, maxY, minX, minY
    dfs(1, -1001, -1001, 1001, 1001);
    cout << res;

   return 0;
}