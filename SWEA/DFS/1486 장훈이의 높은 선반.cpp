#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, B;
int res = 1e9;
vector <int> v;

void dfs(int idx, int sum){
  if (sum >= B) {
    res = min(res, sum - B);
    return;
  }

  for(int i = idx + 1; i < N; i++){
    dfs(i, sum + v[i]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T, TC = 1;
  cin >> T;
  while(T--){
    cin >> N >> B;

    for(int i = 0; i < N; i++){
      int height;
      cin >> height;
      v.push_back(height);
    }
    res = 1e9;
    v.clear();
    dfs(-1, 0);

    cout << "#" << TC << " " << res << " " << "\n";
    TC++;
  }

  return 0;
}
