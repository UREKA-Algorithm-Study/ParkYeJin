#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int answer = 0;

vector<int> info_g;
vector<vector<int>> tree(18);

void dfs(int cur, int sheep, int wolf, queue <int> q){
    info_g[cur] == 0 ? sheep++ : wolf++; 
   
    if (sheep <= wolf) return;
    if (answer < sheep) answer = sheep;
    
    for(int i = 0; i < tree[cur].size(); i++){
        q.push(tree[cur][i]);
    }
    for (int i = 0; i < q.size(); i++) {
        int next = q.front();
        q.pop();
        dfs(next, sheep, wolf, q);
        q.push(next);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    
    info_g.assign(info.begin(), info.end());
    
    for(int i = 0; i < info.size() - 1; i++){
        int x = edges[i][0];
        int y = edges[i][1];
        tree[x].push_back(y);
    }
    
    queue <int> q;
    dfs(0, 0, 0, q);
    
    return answer;
}