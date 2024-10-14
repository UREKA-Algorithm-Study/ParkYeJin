#include <bits/stdc++.h>
using namespace std;

int N, L, R;
int A[101][101];
bool visited[101][101];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

bool bfs(int x, int y){
  queue <pair <int, int>> q;
  vector <pair<int, int>> v;
  q.push({x, y});
  visited[x][y] = true;

  int cnt = 1;
  int sum = A[x][y];
  v.push_back({x, y}); // 연결된 구역들

  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
      int num = abs(A[nx][ny] - A[x][y]);

      if (!visited[nx][ny] && L <= num && num <= R) {
        visited[nx][ny] = true;
        q.push({nx, ny});
        v.push_back({nx, ny});
        cnt += 1;
        sum += A[nx][ny];
      }
    }
  }

  // 인구 이동이 일어난 경우에만 값을 재할당
  if (v.size() > 1) { 
    for(auto iter : v){
      A[iter.first][iter.second] = sum / cnt;
    }
    return true; // 인구 이동 발생
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N >> L >> R;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      cin >> A[i][j];
    }
  }

  int res = 0;
  while(1) {
    bool flag = false; // 인구 이동 발생
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++) {
        if (!visited[i][j]){
          if (bfs(i, j)) flag = true;
        }
      }
    }

    // 벽 허물어지는 게 하나도 없다면 종료
    if (!flag) {
      cout << res;
      break;
    }
    res++;
    memset(visited, 0, sizeof(visited));
  }
  return 0;
} 