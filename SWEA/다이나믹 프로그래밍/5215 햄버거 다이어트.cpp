#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

/*
  백트래킹 시간초과
  DP Knapsack 문제
*/

int N, L, res; // 재료의 수, 제한 칼로리
int score[21], kcal[21];
int dp[21][10001]; // N, kcal;

void dynamic(){
  // 재료의 수
  for(int i = 1; i <= N; i++){
    // 제한 칼로리
    for(int j = 1; j <= L; j++){
      // 현재 음식을 넣을 수 있다면
      if (kcal[i] <= j) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - kcal[i]] + score[i]);
      } 
      // 현재 음식 못 넣는다면
      else dp[i][j] = dp[i - 1][j];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T, TC = 1;
  cin >> T;
  while(T--){
    cin >> N >> L;

    for(int i = 1; i <= N; i++){
      cin >> score[i] >> kcal[i];
    }
    res = 0;
    dynamic();
    res = dp[N][L];

    cout << "#" << TC << " " << res << "\n";
    TC++;
  }

  return 0;
}
