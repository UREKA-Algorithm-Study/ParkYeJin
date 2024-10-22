#include <bits/stdc++.h>
using namespace std;

/*
  1. (1, 1) 흰색
  2. (1, 1) 검은색
  체스판 8 x 8 을 골랐을 때
  다시 칠해야하는 정사각형 최소 개수
*/

int M, N;
char arr[51][51];

int check(int x, int y, char start) {
  int cnt = 0; // 바꿔야하는 수
  for(int i = x; i < x + 8; i++){
    for(int j = y; j < y + 8; j++){
      if ((i + j) % 2 == 0) {
        if(arr[i][j] != start) cnt++;
      } else {
        if (arr[i][j] == start) cnt++;
      }
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> M >> N;
  for(int i = 1; i <= M; i++){
    for(int j = 1; j <= N; j++){
      cin >> arr[i][j];
    }
  }

  int res = 3000;
  for(int i = 1; i < M - 6; i++){ // x 시작점
    for(int j = 1; j < N - 6; j++){ // y 시작점
      res = min(res, check(i, j, 'B')); // 검은색일 경우
      res = min(res, check(i, j, 'W')); // 흰색일 경우
    }
  }
  cout << res;

  return 0;
} 