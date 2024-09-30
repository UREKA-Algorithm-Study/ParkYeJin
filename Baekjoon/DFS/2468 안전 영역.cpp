#include <bits/stdc++.h>
using namespace std;

int N, arr[101][101];
int height[101][101];
bool visited[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1}; 

int minN = 100, maxN = 0;

void dfs(int x, int y) {
  visited[x][y] = true;

  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
    if (arr[nx][ny] && !visited[nx][ny]){
      dfs(nx, ny);
    }
  }
  return;
}

int main() {
  cin >> N;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      cin >> height[i][j];
      maxN = max(maxN, height[i][j]);
      minN = min(minN, height[i][j]);
    }
  }
  
  int res = 0;
  for(int k = minN; k <= maxN; k++){
    memset(arr, 0, sizeof(arr));
    memset(visited, 0, sizeof(visited));

    // height에 따른 새로운 배열
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        if (height[i][j] >= k) {
          arr[i][j] = 1;
        }
      }
    }

    int cnt = 0;
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        if (!visited[i][j] && arr[i][j]) {
          dfs(i, j);
          cnt++;
        }
      }
    }
    res = max(res, cnt);
  }
  cout << res;

  return 0;
} 