#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

/*
  가장 나중에 연락을 받게 되는 사람 중
  번호가 가장 큰 사람
*/

int N, start, res, depth;
bool visited[101];

vector <vector <int>> v;
queue <pair <int, int>> q; // 순서, 값

void bfs(int cur){
  q.push({0, cur}); // 가장 첫번째 연락
  visited[cur] = true;

  while(!q.empty()){
    int now = q.front().second;
    int nowDepth = q.front().first;
    q.pop();

    if (depth < nowDepth) {
      depth = nowDepth;
      res = now;
    } else if (depth == nowDepth) {
      res = max(res, now);
    }

    for(int i = 0; i < v[now].size(); i++){
      int next = v[now][i];
      if (!visited[next]) {
        q.push({nowDepth + 1, next});
        visited[next] = true;
      }
    }
  }
}

int main() {
  int T = 10, TC = 1;
  while(T--){
    cin >> N >> start;
    v = vector<vector<int>>(101);  

    int from, to;
    for(int i = 0; i < N; i += 2){
      scanf("%d %d", &from, &to);
      // 중복 간선 검사
      if (find(v[from].begin(), v[from].end(), to) == v[from].end()) {
        v[from].push_back(to);
      }
    }

    memset(visited, 0, sizeof(visited));
    res = 0;
    depth = 0;

    bfs(start);

    cout << "#" << TC << " " << res << "\n";
    TC++;
  }

  return 0;
}
