#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

vector <vector <int>> v(100);
bool visited[100];

void dfs(int now){
  visited[now] = true;

  for(int i = 0; i < v[now].size(); i++){
    int next = v[now][i];
    if (!visited[next]) dfs(next);
  }
}

int main() {
  int T = 10;
  while(T--){
    int TC, route;
    scanf("%d %d", &TC, &route);

    int x, y;
    for(int i = 0; i < route; i++){
      scanf("%d %d", &x, &y);
      v[x].push_back(y);
    }

    dfs(0);

    int res = visited[99] ? 1 : 0;
    cout << '#' << TC << ' ' << res << "\n";

    // 초기화
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < 100; i++) {
      v[i].clear();
    }
  }
}