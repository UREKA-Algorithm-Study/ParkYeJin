#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

/* 
  N개의 퀸
  같은 행, 같은 열, 대각선 공격 가능  
*/

int N, res;
bool col[11];
bool leftDiag[22]; // 좌상우하 ↘ 차가 일정
bool rightDiag[22]; // 우상좌하 ↙ 합이 일정

void game(int row) {
  if (row == N) { 
    res++;
    return;
  }

  for (int i = 0; i < N; i++) {
    if (!col[i] && !leftDiag[row - i + N - 1] && !rightDiag[row + i]) {
      col[i] = leftDiag[row - i + N - 1] = rightDiag[row + i] = true;
      game(row + 1); 
      col[i] = leftDiag[row - i + N - 1] = rightDiag[row + i] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T, TC = 1;
  cin >> T;
  while(T--){
    cin >> N;
    res = 0;
    memset(col, 0, sizeof(col));
    memset(leftDiag, 0, sizeof(leftDiag));
    memset(rightDiag, 0, sizeof(rightDiag));
    game(0);
    cout << "#" << TC << " " << res << "\n";
    TC++;
  }

  return 0;
}
