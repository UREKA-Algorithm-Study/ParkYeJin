#include <iostream>
#include <vector>
using namespace std;

int n, k, cnt;
vector<int> v;

void backtracking(int sum) {
  if (sum == n) {
    cnt++;
    if (cnt == k) {
      for(int i = 0; i < v.size(); i++) {
        cout << v[i];
        if(i != v.size() - 1) cout << "+";
      }
    }
    return;
  }

  for (int i = 1; i <= 3; i++) {
    if (sum + i <= n) {
      v.push_back(i);
      backtracking(sum + i);
      v.pop_back();
    }
  }
}

int main() {
  cin >> n >> k;
  backtracking(0);
  // k개보다 적은 경우
  if (cnt < k) cout << -1;
  return 0;
}
