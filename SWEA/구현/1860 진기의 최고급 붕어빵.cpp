#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int dp[11112];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T, TC = 1;
  cin >> T;
  while(T--){
    int N, M, K;
    cin >> N >> M >> K; // N명, M초 시간, K개

    int cnt = 0;
    for(int i = M; i < 11111; i++){
      if (i % M == 0) cnt += K;
      dp[i] = cnt;
    }

    vector <int> v; // 초
    for(int i = 0; i < N; i++){
      int num;
      cin >> num;
      v.push_back(num);
    }
    sort(v.begin(), v.end());

    bool flag = true;
    for(int i = 0; i < N; i++){
      if (dp[v[i]] - (i + 1) < 0) flag = false;
    }

    string res = flag ? "Possible" : "Impossible"; 
    cout << "#" << TC << " " << res << "\n";
    TC++;

    memset(dp, 0, sizeof(dp));
  }

  return 0;
}
