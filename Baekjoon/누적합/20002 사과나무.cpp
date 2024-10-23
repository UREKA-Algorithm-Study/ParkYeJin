#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

/* 
  2차원 누적합
  정사각형의 과수원 N*N
  가능한 모든 크기의 정사각형을 탐색
*/

int N, res = -1e9;
int arr[301][301];
int sum[301][301];

void game(int x, int y, int size) {
  int x1 = x;
  int y1 = y;
  int x2 = x + size - 1;
  int y2 = y + size - 1;

  if (x2 > N || y2 > N) return; // 범위를 벗어나면 패스
  int num = sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
  res = max(res, num);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  
  cin >> N;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> arr[i][j];
      sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
    }
  }

  for(int size = 1; size <= N; size++) {
    for(int i = 1; i <= N - size + 1; i++) {
      for(int j = 1; j <= N - size + 1; j++) {
        game(i, j, size);
      }
    }
  }
  
  cout << res;

  return 0;
}


// 시간초과 4중 for문
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, K, res = -1e9;
int arr[301][301];
int sum[301][301];

void game(int x, int y){
  for(int i = x; i <= N; i++){
    for(int j = 0; j <= N; j++){
      int x1 = x;
      int y1 = y;
      int x2 = x + j;
      int y2 = y + j;

      if (x1 > N || y1 > N || x2 > N || y2 > N) continue;
      int num = sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] +  sum[x1-1][y1-1];
      res = max(res, num);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  
  cin >> N;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      cin >> arr[i][j];
      sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
    }
  }

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      // 시작점
      game(i, j);
    }
  }
  cout << res;

  return 0;
}
