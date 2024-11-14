#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N, K, res;
int arr[21];

void dfs(int idx, int sum){
  if (sum > K) {
    return;
  }
  if (sum == K) {
    res++;
    return;
  }

  for(int i = idx + 1; i < N; i++){
    dfs(i, sum + arr[i]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T, TC = 1;
  cin >> T;
  while(T--){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
      cin >> arr[i];
    }
    res = 0;
    sort(arr, arr + N);
    dfs(-1, 0);

    cout << "#" << TC << " " << res << "\n";
    TC++;
  }

  return 0;
}
