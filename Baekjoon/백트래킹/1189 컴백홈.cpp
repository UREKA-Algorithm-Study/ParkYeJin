#include <bits/stdc++.h>
using namespace std;

/*
  한수 - 왼쪽 아래
  집 - 오른쪽 위
  재방문 x
  T- 가지 못하는 부분
  집까지 도착하는 경우 중 거리가 K인 가짓수
*/

int R, C, K, res;
char arr[6][6];
bool visited[6][6];

const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};

void dfs(int x, int y, int depth){
  if (x == 1 && y == C) {
    if (depth == K - 1) res++;
    return;
  }
  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
    if (!visited[nx][ny] && arr[nx][ny] != 'T') {
      visited[nx][ny] = true;
      dfs(nx, ny, depth + 1);
      visited[nx][ny] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> R >> C >> K;
  for(int i = 1; i <= R; i++){
    for(int j = 1; j <= C; j++){
      cin >> arr[i][j];
    }
  }

  // 한수 위치
  visited[R][1] = true;
  dfs(R, 1, 0);
  cout << res;

  return 0;
} 