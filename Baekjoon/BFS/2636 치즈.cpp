#include <bits/stdc++.h>
using namespace std;

int N, M, block = 10001;
int arr[101][101];
bool visited[101][101];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

/*
  (1, 1) 시작
  1인 곳 방문하되, q넣지는 x, 0으로 변경하고
  모든 게 0될때까지 반복
*/

void bfs(int x, int y) {
  queue <pair <int, int>> q;
  q.push({x, y});
  visited[x][y] = true;
  
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
      if (!visited[nx][ny]){
        visited[nx][ny] = true;
        if (arr[nx][ny] == 0) {
          q.push({nx, ny});
        } else { // arr[nx][ny] == 1
          arr[nx][ny] = 0;
        }
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

  int time = 0;
  while(1) {
    memset(visited, 0, sizeof(visited));

    int cnt = 0;
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= M; j++){
        if (arr[i][j] == 1) cnt++;
      }
    }
    // 반례: 처음부터 cnt가 0이라면? time 0, block 0

    // 모든 게 0이 됐음
    if (cnt == 0) {
      if (block == 10001) block = 0;
      break;
    }
    // 모두 녹기 1시간 전
    if (cnt != 0) block = min(block, cnt);

    bfs(1, 1);
    time++;
  }
  
  cout << time << "\n" << block;

  return 0;
} 