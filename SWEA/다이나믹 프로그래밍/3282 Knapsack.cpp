#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
int V[101], C[101];
int dp[101][1001];

void knapsack(){
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= K; j++){
      // 넣을 수 있는 경우
      if (j >= V[i]) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - V[i]] + C[i]);
      }
      // 못 넣는 경우
      else dp[i][j] = dp[i - 1][j];
    }
  }
}

int main() {
  int T, TC = 1;
  cin >> T;
  while(T--){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
      cin >> V[i] >> C[i];
    }

    knapsack();
    cout << "#" << TC << " " << dp[N][K] << "\n";
    TC++;

    memset(dp, 0, sizeof(dp));
  }
}