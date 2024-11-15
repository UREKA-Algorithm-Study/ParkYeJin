#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

/*
  자신이 놓을 돌과 자신의 돌 사이(가로 세로 대각선)에
  상대편 돌이 있을 경우에만 돌을 놓을 수 있음
  사이에 1개 이상의 돌
*/

int arr[9][9];
int N, M; // 한 변의 길이 (4 6 8), 돌을 놓는 횟수  

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void placeStone(int x, int y, int kind) {
  arr[x][y] = kind;

  for(int i = 0; i < 8; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    bool valid = false;

    while(nx >= 1 && nx <= N && ny >= 1 && ny <= N && arr[nx][ny] != 0 && arr[nx][ny] != kind) {
      nx += dx[i];
      ny += dy[i];

      if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && arr[nx][ny] == kind) {
        valid = true;
        break;
      }
    }

    // 내 돌이 있을 경우
    if (valid) {
      nx = x + dx[i];
      ny = y + dy[i];

      while(arr[nx][ny] != kind) {
        arr[nx][ny] = kind;
        nx += dx[i];
        ny += dy[i];
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T, TC = 1;
  cin >> T;
  while(T--){
    cin >> N >> M;
    memset(arr, 0, sizeof(arr));

    arr[N / 2][N / 2] = 2;
    arr[N / 2][N / 2 + 1] = 1;
    arr[N / 2 + 1][N / 2] = 1;
    arr[N / 2 + 1][N / 2 + 1] = 2;

    // 돌을 놓을 위치, 돌의 색(1-흑, 2-백)
    for(int i = 0; i < M; i++){
      int x, y, kind;
      cin >> y >> x >> kind;
      placeStone(y, x, kind);
    }

    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        if (arr[i][j] == 1) cnt1++;
        else if (arr[i][j] == 2) cnt2++;
      }
    }

    cout << "#" << TC << " " << cnt1 << " " << cnt2 << "\n";
    TC++;

  }

  return 0;
}
