#include <iostream>
#include <algorithm>

using namespace std;

/*
  가치 10만, 2차원 배열 불가
*/

int n, k;
int dp[100001];
int coin[101];

void dynamic(){
  dp[0] = 0;
  for(int i = 1; i <= k; i++){
    dp[i] = 1e9;
  }

  for(int i = 0; i < n; i++) { // 동전 개수만큼
    for(int j = coin[i]; j <= k; j++) { // 동전 값을 기준으로 업데이트
      dp[j] = min(dp[j], dp[j - coin[i]] + 1);
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
  
  if (dp[k] == 1e9) cout << -1;
  else cout << dp[k];

  return 0;
}
