#include <iostream>
#include <algorithm>

using namespace std;

int N, K; // 물품의 수, 버틸 수 있는 무게
int W[101], V[101]; // 각 물건의 무게, 가치
int dp[101][100001];

void dynamic() {
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= K; j++){
      // 담을 수 있는 경우
      if (j >= W[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
      // 담을 수 없는 경우
      else dp[i][j] = dp[i - 1][j];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  
  cin >> N >> K;
  for(int i = 1; i <= N; i++){
    cin >> W[i] >> V[i];
  }
  dynamic();
  cout << dp[N][K];
  
  return 0;
}
