#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

/*
  무방향 그래프 
  최장 경로의 길이
*/

int N, M, res; // 정점, 간선
bool visited[11];
vector <vector <int>> v;

void dfs(int cur, int depth){
  res = max(res, depth);

  for(int i = 0; i < v[cur].size(); i++){
    if (!visited[v[cur][i]]) {
      visited[cur] = true;
      dfs(v[cur][i], depth + 1);
      visited[cur] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T, TC = 1;
  cin >> T;
  while(T--){
    cin >> N >> M;

    v = vector <vector <int>>(N + 1);
    for(int i = 0; i < M; i++){
      int x, y; 
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x);
    }

    res = 0;
    for(int i = 1; i <= N; i++){
      memset(visited, 0, sizeof(visited));
      dfs(i, 1);
    }

    cout << "#" << TC << " " << res << "\n";
    TC++;
  }

  return 0;
}
