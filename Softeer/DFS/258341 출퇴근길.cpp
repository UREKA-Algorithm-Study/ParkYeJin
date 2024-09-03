#include<iostream>
#include<vector>

using namespace std;

int n, m, S, T;

vector<vector<int>> edge;
vector<vector<int>> redge;

vector<bool> fromS, fromT, toS, toT;

void dfs(int now, vector<vector<int>> &v, vector<bool> &visited){
    if (visited[now]) return;
    visited[now] = true;

    for(int i = 0; i < v[now].size(); i++){
        dfs(v[now][i], v, visited);
    }
    return;
}

int main(int argc, char** argv)
{    
    cin >> n >> m;
    edge.resize(n+1);
    redge.resize(n+1);

    fromS.resize(n+1);
    fromT.resize(n+1);
    toS.resize(n+1);
    toT.resize(n+1);
    
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        redge[y].push_back(x);
    }
    cin >> S >> T;

    fromS[T] = true;
    dfs(S, edge, fromS);
    fromT[S] = true;
    dfs(T, edge, fromT);

    dfs(S, redge, toS);
    dfs(T, redge, toT);

    int res = 0;
    for(int i = 1; i <= n; i++){
        if (fromS[i] && fromT[i] && toS[i] && toT[i]) res++;
    }
    cout << res - 2;
    
   return 0;
}