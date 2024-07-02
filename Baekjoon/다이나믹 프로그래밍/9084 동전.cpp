#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M; // 동전수, 동전으로 만들어야 할 금액
int coin[21]; // 각 동전 금액
int dp[10001];

void dynamic(){
  dp[0] = 1;
  
  for(int i = 1; i <= N; i++){
    for(int j = coin[i]; j <= M; j++){
      dp[j] += dp[j - coin[i]];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  
  int T;
  cin >> T;
  
  while(T--){
    cin >> N;
    for(int i = 1; i <= N; i++){
      cin >> coin[i];
    }
    cin >> M;
    dynamic();

    cout << dp[M] << "\n";
    memset(dp, 0, sizeof(dp));
  }
  
  return 0;
}
