#include <bits/stdc++.h>
using namespace std;

int N, dv;
bool visited[51];
vector <int> parent[51];

// 삭제되는 노드 다 방문
void dfs(int dv){
  visited[dv] = true;
  if (parent[dv].size() == 0) {
    return;
  }

  for(int i = 0; i < parent[dv].size(); i++){
    dfs(parent[dv][i]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++){
    int v;
    cin >> v;
    if (v == -1) continue;
    parent[v].push_back(i);
  }
  cin >> dv;
  dfs(dv);

  int res = 0;
  for(int i = 0; i < N; i++){
    int cnt = 0;
    for(int j = 0; j < parent[i].size(); j++){
      if (visited[parent[i][j]]) cnt++;
    }
    // 방문 x && 삭제된 노드 = 자식 노드의 개수
    if (!visited[i] && cnt == parent[i].size()) res++;
  }
  cout << res;

  return 0;
} 