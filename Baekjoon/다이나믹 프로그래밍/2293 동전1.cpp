#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

/*
  동전의 가치 100000
  2차원 배열 불가
  if (j >= coin[i]) // 가치
  dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i]]
*/

int n, k; // 동전수, 동전으로 만들어야 할 금액
int coin[101]; // 각 동전 금액
int dp[10001];

void dynamic(){
  dp[0] = 1; // 하나도 안 쓰는 경우의 수
  
  for(int i = 0; i < n; i++){ // 개수
    for(int j = coin[i]; j <= k; j++){ // 가치
      dp[j] += dp[j - coin[i]];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> coin[i];
  }
  dynamic();

  cout << dp[k] << "\n";
  
  return 0;
}
