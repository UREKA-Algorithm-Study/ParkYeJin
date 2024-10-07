#include <bits/stdc++.h>
using namespace std;

int N, M, res;
int arr[9][9];
int copy_arr[9][9];
bool visited[9][9];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1}; 

// 0 빈칸, 1 벽, 2 바이러스
void bfs(int x, int y){
  queue <pair <int, int>> q;
  q.push({x, y});
  visited[x][y] = true;

  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
      if (!visited[nx][ny] && copy_arr[nx][ny] == 0) {
        q.push({nx, ny});
        copy_arr[nx][ny] = 2;
        visited[nx][ny] = true;
      }
    }
  }
  return;
}

// 벽세우기
void wall(int cnt){
  if (cnt == 3) {
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= M; j++){
        copy_arr[i][j] = arr[i][j];
      }
    }
    // 2 바이러스로 다 채우기
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= M; j++){
        if (!visited[i][j] && copy_arr[i][j] == 2) {
          bfs(i, j);
        }
      }
    }
    // 0 안전영역 개수
    int cnt = 0;
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= M; j++){
        if (copy_arr[i][j] == 0) {
          cnt++;
        }
      }
    }
    res = max(cnt, res);
    return;
  }
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      if (arr[i][j] == 0){
        arr[i][j] = 1;
        wall(cnt + 1);
        arr[i][j] = 0;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      cin >> arr[i][j];
    }
  }
  
  wall(0);
  cout << res;

  return 0;
} 