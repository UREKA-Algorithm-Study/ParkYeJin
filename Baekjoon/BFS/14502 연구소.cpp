#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
  0 빈칸, 1 벽, 2 바이러스
  세울 수 있는 벽 3개, 꼭 3개 세워야함
*/

int N, M, res = 0;
int arr[9][9], arr_copy[9][9];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

vector <pair <int, int>> v;

void bfs(){
  queue <pair <int, int>> q;
  // 바이러스 초기 위치
  for(int i = 0; i < v.size(); i++){
    q.push({v[i].first, v[i].second});
  }

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 1 || nx > N || ny < 1 || ny > M)
        continue;
      // 새로운 벽이 생긴 영역에서 바이러스 감염
      if (arr_copy[nx][ny] == 0) {
        arr_copy[nx][ny] = 2;
        q.push({nx, ny});
      }
    }
  }

  int cnt = 0;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      if (arr_copy[i][j] == 0) cnt++;
    }
  }
  res = max(res, cnt);
}

void wall(int cnt) {
  if (cnt == 3) { // 벽이 3개 됐을 때
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= M; j++){
        arr_copy[i][j] = arr[i][j];
      }
    }
    bfs();
    return;
  }
  // 벽 세우기
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      if (arr[i][j] == 0) {
        arr[i][j] = 1;
        wall(cnt + 1);
        arr[i][j] = 0;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      cin >> arr[i][j]; 
      // 바이러스일 경우
      if (arr[i][j] == 2) { 
        v.push_back({i, j});
      }
    }
  }
  // 0인 부분들 모두 벽 세워보기
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      if (arr[i][j] == 0) {
        arr[i][j] = 1; // 벽
        wall(1);
        arr[i][j] = 0;
      }
    }
  }
  cout << res;
  
  return 0;
}