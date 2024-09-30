#include <bits/stdc++.h>
using namespace std;

int M, N, K, res, cnt;
int arr[101][101];
bool visited[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1}; 

int dfs(int x, int y){
  int cnt = 1;
  visited[x][y] = true;

  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || nx > M - 1 || ny < 0 || ny > N - 1) continue;
    if (!visited[nx][ny] && !arr[nx][ny]) {
      cnt += dfs(nx, ny);
    }
  }
  return cnt;
}

int main() {
  cin >> M >> N >> K;
  for(int i = 0; i < K; i++){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int j = y1; j < y2; j++){
      for(int k = x1; k < x2; k++){
        arr[j][k] = 1;
      }
    }
  }

  vector <int> v;
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      if (!visited[i][j] && !arr[i][j]){
        v.push_back(dfs(i, j));
        res++;
      }
    }
  }
  cout << res << "\n";
  sort(v.begin(), v.end());
  for(auto i : v) {
    cout << i << " ";
  }

  return 0;
} 