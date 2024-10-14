#include <bits/stdc++.h>
using namespace std;

int N, M, res;
string arr[51];
int dist[51][51];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

void bfs(int x, int y){
  memset(dist, 0, sizeof(dist));
  queue <pair <int, int>> q;
  q.push({x, y});
  dist[x][y] = 1;

  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) continue;
      if (!dist[nx][ny] && arr[nx][ny] == 'L') {
        q.push({nx, ny});
        dist[nx][ny] = dist[x][y] + 1;
        res = max(res, dist[nx][ny] - 1);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N >> M;
  for(int i = 0; i < N; i++){
    cin >> arr[i];
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if (arr[i][j] == 'L') bfs(i, j);
    }
  }
  cout << res;
  return 0;
} 