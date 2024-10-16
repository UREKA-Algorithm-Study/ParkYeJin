#include <bits/stdc++.h>
using namespace std;

/*
  주난 *
  초코바 가진 학생 #
  장애물 없는 빈 공간 0
  친구들 1
*/

int N, M;
int x1, y11, x2, y2; // 주난, 범인 위치
char arr[301][301];
bool visited[301][301];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

bool bfs(){
  queue <pair <int, int>> q;
  q.push({x1, y11});
  visited[x1][y11] = true;

  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
      if (visited[nx][ny]) continue;

      if (arr[nx][ny] != '#') {
        visited[nx][ny] = true;
        if (arr[nx][ny] == '0') {
          q.push({nx, ny});
        }
        else if (arr[nx][ny] == '1') {
          arr[nx][ny] = '0';
        }
      } else {
        return true;
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N >> M;
  cin >> x1 >> y11 >> x2 >> y2;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      cin >> arr[i][j];
    }
  }

  int cnt = 0;
  while(1) {
    cnt++;
    if (bfs()) break;
    memset(visited, 0, sizeof(visited));
  }

  cout << cnt;
  return 0;
} 